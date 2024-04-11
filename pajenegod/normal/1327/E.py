import sys
range = xrange
input = raw_input

MOD = 998244353
n = int(input())

out = [0]*n
out[-1] = 10

for i in range(1, n): 
    free = n - i
    ans = 18 * pow(10, free - 1, MOD) % MOD
    if free >= 2:
        ans = (ans + (n - (i - 1) - 2) * pow(10, free - 2, MOD) * pow(9, 2, MOD) ) % MOD
    
    out[i - 1] = int(ans * 10 % MOD)

print ' '.join(str(x) for x in out)