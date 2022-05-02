#include <stdio.h>
#include <time.h>

/** This is a minor modification of the genuine C program of the sieve benchmark.
    Loop conditions and certain expressions have been made optimizer friendly. **/

#define true 1
#define false 0
#define size 80000000
#define sizepl 80000001
char flags[sizepl];

void main() {
    int i, prime, k, count, iter;

    printf("10 iterations\n");

    clock_t t;
    t = clock();

    for (iter = 1; iter <= 10; iter ++) {
        count=0 ;
	for (i = 0; i != sizepl; i++)
	    flags[i] = true;
        for (i = 0; i != sizepl; i++) {
	    if (flags[i]) {
                prime = i + i + 3;
                k = prime + i;
                while (size - k >= 0) {
                    flags[k] = false;
                    k += prime;
                }
                count = count + 1;
            }
        }

    }


    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\n%d primes\n", count);
    printf("\nTook %f seconds to execute \n", time_taken);
    printf("\nYour machine is %f times faster than Win10-X86-PC/i3-4000M(C)-ToughSieve-benchmark\n", 29.873000/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/Ryzen7-1700X(C)-ToughSieve-benchmark\n", 23.778366/time_taken);
	printf("Your machine is %f times faster than Win10-X86-PC/Ryzen7-1700X(C)-ToughSieve-benchmark\n", 22.624000/time_taken);
    printf("Your machine is %f times faster than Linux-X86-PC/i7-8850H(C)-ToughSieve-benchmark\n", 12.723097/time_taken);
	printf("Your machine is %f times faster than Win10-X86-PC/i7-8850H(C)-ToughSieve-benchmark\n", 12.723097/time_taken);

}
