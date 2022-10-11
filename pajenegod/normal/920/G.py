import sys
range = xrange
input = raw_input

big = 10**6 + 1
prime_div = [1]*big

for p in range(2, big):
    if prime_div[p] == 1:
        for i in range(p, big, p):
            prime_div[i] = p

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
out = []
for _ in range(t):
    x = inp[ii]; ii += 1
    p = inp[ii]; ii += 1
    k = inp[ii]; ii += 1

    to_add = [1]
    to_sub = []
    while p > 1:
        prime = prime_div[p]
        while p % prime == 0:
            p //= prime

        tmp = list(to_add)
        to_add += (y * prime for y in to_sub)
        to_sub += (y * prime for y in tmp)
    
    def counter(n):
        ans = 0
        for d in to_add:
            ans += n // d
        for d in to_sub:
            ans -= n // d
        return ans

    base = counter(x)
    l = 0
    r = 10**9
    while l < r:
        mid = l + r >> 1
        if counter(mid) - base >= k:
            r = mid
        else:
            l = mid + 1
    out.append(l)
print '\n'.join(str(x) for x in out)