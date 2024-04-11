MOD = 10**9 + 7


def fast_pow(k):
    product = 1
    base = 2
    while k:
        if k & 1:
            product *= base
            product %= MOD
        base *= base
        base %= MOD
        k //= 2
    return product


s = input()
s = s.split()
N = int(s[0])
M = int(s[1])
K = int(s[2])
if (N + M) & 1 and K == -1:
    print(0)
else:
    print(fast_pow((N - 1) * (M - 1)))