import math
import random
import sys

QUERIES = 80

N = int(input())
factors = [N]

for q in range(QUERIES):
    x = random.randint(1, N - 1)
    print('sqrt', x * x % N)
    sys.stdout.flush()
    y = int(input())

    if x != y and x + y != N:
        diff = abs(x - y)
        new_factors = []

        for value in factors:
            combined = math.gcd(diff, value)
            other = value // combined

            if combined != 1:
                new_factors.append(combined)

            if other != 1:
                new_factors.append(other)

        factors = new_factors

print('!', len(factors), *factors)