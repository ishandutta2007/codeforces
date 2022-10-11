big = 10**5

n =int(input())
arr = [int(x) for x in input().split()]

freq = [0]*(big + 1)
for i in arr:
    freq[i] += 1

dp = {}
for a in range(big+1):
    if(a==0):
        val = 0
    elif(a==1):
        val = freq[1]
    else:
        val = max(dp[a-1], dp[a-2]+a*freq[a])
    dp[a] = val

print(dp[big])