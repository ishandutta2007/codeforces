MOD = 998244353
def inv(x):
    return pow(x, MOD - 2, MOD)
 
n, m = map(int, raw_input().split())
 
mult = n * inv(m + 1) + 1
mult %= MOD
 
currN = 1
out = m + 1
while currN < n:
    currN += 1
 
    out = (out + m * inv(currN)) % MOD
 
out *= mult
print(out % MOD)