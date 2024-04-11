import sys
range = xrange
input = raw_input

n,x,y = [int(x) for x in input().split()]

x = x + 0.0
y = y + 0.0

DP = [0.0]*(n+2)
DP[-1] = 1
for i in range(1,n+1):
    DP[i] = min(DP[i-1] + x, DP[(i+1)//2] + y + (x if i&1 else 0.0))

print int(DP[n])