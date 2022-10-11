import sys
range = xrange
input = raw_input
 
n, m = [int(x) for x in input().split()]
orda = ord('a')
S = [ord(c) - orda for c in input()]
 
trans = [[0]*m for _ in range(m)]
for i in range(n - 1):
    if S[i] < S[i + 1]:
        trans[S[i]][S[i + 1]] += 1
    elif S[i] > S[i + 1]:
        trans[S[i + 1]][S[i]] += 1
 
for c1 in range(m):
    for c2 in range(c1 + 1, m):
        trans[c2][c1] = trans[c1][c2]

left = [0]*m
DP = [-1]*(2**m)
DP[0] = 0
 
score = [0]*n
for c1 in range(m):
    for c2 in range(m):
        score[c1] -= trans[c1][c2]
 
for c1 in range(m):
    for c2 in range(m):
        trans[c1][c2] *= 2

s = 0
for i in range(1, 2**m):
    j = 0
    while left[j]:
        t = trans[j]
        for c2 in range(m):
            score[c2] -= t[c2]
        
        left[j] = 0
        j += 1
    s += 1 - j

    left[j] = 1
    t = trans[j]
    for c2 in range(m):
        score[c2] += t[c2]

    
    besta = 10**9
    for x in range(m):
        val = DP[i ^ (1 << x)] + s * score[x]
        if i & (1 << x) and val < besta:
            besta = val
    DP[i] = besta
 
print DP[-1]