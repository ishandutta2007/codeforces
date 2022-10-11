import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
def fac(x):
    i = 1
    for j in range(2 , x + 1):
        i = i * j % MOD
    return i

fac = [1]
for i in range(1, 10**6 + 10):
    fac.append(int(fac[-1] * i % MOD))

n = int(input())
def ways(prevg, g):
    cur = n//g - n//prevg if prevg else n//g
    left = n - n//g

    a = cur
    for i in range(left + 1, left + cur):
        a = a * i % MOD
    #a = fac[cur] * pow(left+1, cur - 1, MOD)
    b = +(g == 1)
    for x in 2,3:
        if g % x == 0:
            b += ways(g, g // x)
    return a * b

a = 1
while a * 2 <= n:
    a *= 2

ans = ways(0, a)
if a //2 * 3 <= n:
    ans += ways(0, a //2 * 3)

print ans % MOD