import sys
range = xrange
input = raw_input

n,h,l,r = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

DP = [[0]*h for _ in range(n + 1)]
for i in reversed(range(n)):
    for t in range(h):
        a = (t + A[i]) % h
        b = (a - 1) % h
        DP[i][t] = max(DP[i + 1][a] + (l <= a <= r), DP[i + 1][b] + (l <= b <= r))

print DP[0][0]