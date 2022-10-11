MOD = 998244353
MODF = 1.0*MOD
MODF_inv = 1.0/MODF
SHRT = 1.0*(1 << 16)
SHRT_inv = 1.0/SHRT
MAGIC = 1.0*(2**52+2**51)
fround = lambda x:(x+MAGIC)-MAGIC
modder = lambda a:a - MODF * fround(a*MODF_inv)
mod_prod = lambda a, b, c=0.0:\
    modder(modder(a * SHRT) * fround(SHRT_inv*b) + a*(b-SHRT * fround(b*SHRT_inv))+ c)

#aeternalis1 code, with new and improved modder
n = int(raw_input())
nums = list(map(int,raw_input().split()))
dp = [0.0 for x in range(n)]
combs = [[0.0 for x in range(1001)] for x in range(1001)]
for i in range(1001):
  for j in range(i+1):
    if not j:
      combs[i][j] = 1.0
    elif j:
      combs[i][j] = modder(combs[i-1][j]+combs[i-1][j-1])
for i in range(n-1,-1,-1):
  if nums[i] > 0 and nums[i]+i<n:
    dp[i] = combs[n-i-1][nums[i]]
    for j in range(nums[i]+i+1,n):
      dp[i] = mod_prod(dp[j],combs[j-i-1][nums[i]],dp[i])
print int(sum(dp))%998244353