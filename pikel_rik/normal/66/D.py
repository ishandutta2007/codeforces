import math as m

n = int(input())

if n == 2:
    print(-1)
    exit(0)

primes = []

i = 2
while len(primes) < n:
    flag = 1
    for j in range(2, i):
        if i % j == 0:
            flag = 0
    if flag == 1:
        primes.append(i)
    i += 1


product = 1
for i in primes:
    product *= i


for i in primes:
    print(product // i)