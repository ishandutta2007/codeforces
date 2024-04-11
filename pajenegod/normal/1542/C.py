import sys
range = xrange
input = raw_input

big = 10**4
P = list(range(big))
for i in range(2, big):
    if P[i] == i:
        for j in range(2*i, big, i):
            P[j] = i

def is_prime_power(x):
    if x <= 1:
        return False
    p = P[x]
    while x % p == 0:
        x //= p
    return x == 1

is_prime_power = [+is_prime_power(x) for x in range(100)]

MOD = 10**9 + 7

t = int(input())
for _ in range(t):
    n = int(input())
    i = 2
    count = 0
    while n:
        p = P[i]

        count += i * (n - (n//p)) % MOD
        n //= p

        i += 1
        while not is_prime_power[i]:
            i += 1

    print count % MOD