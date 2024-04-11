import sys
range = xrange
input = raw_input

MOD = 10**9+7

n = int(input())
m = 2*n

s = 0

DP = [[0]*(n+2) for _ in range(m+1)]
DP[0][0] = 1

for left in range(1,m+1):
    for extra in range(min(left,m-left)+1):
        DP[left][extra] = (DP[left-1][extra-1] + DP[left-1][extra+1])%MOD
        if extra&1:
            s = (s + DP[left][extra])%MOD

print s