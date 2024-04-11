n = int(input())

prime = [1 for i in range(1001)]
primes = []

for i in range(2, 1000 + 1):
    if prime[i] == 1:
        for j in range(i * i, 1000 + 1, i):
            prime[j] = 0
        primes.append(i)


def recurse(n, last):
    if n == 1:
        return 1

    ans = 10**18

    for i in range(2, n + 1):
        if n % i == 0:
            ans = min(ans, primes[last]**(i - 1) * recurse(n // i, last + 1))

    return ans


print(recurse(n, 0))