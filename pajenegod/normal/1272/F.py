import sys
range = xrange
input = raw_input

A = [+(c == ')') for c in input()]
B = [+(c == ')') for c in input()]

n = len(A)
m = len(B)

big = 10**8

DP = [[[big]*201 for _ in range(n + 1)] for _ in range(m + 1)]
DP[0][0][0] = 0
way = [[[-1]*201 for _ in range(n + 1)] for _ in range(m + 1)]

for j in range(m + 1):
    for i in range(n + 1):
        DPji = DP[j][i]
        
        iprim = i + (i < n and A[i] == 0)
        jprim = j + (j < m and B[j] == 0)
        for k in range(200):
            val = DPji[k] + 1
            if DP[jprim][iprim][k + 1] > val:
                DP[jprim][iprim][k + 1] = val
                way[jprim][iprim][k + 1] = 0
        
        iprim = i + (i < n and A[i] == 1)
        jprim = j + (j < m and B[j] == 1)
        for k in reversed(range(1, 201)):
            val = DPji[k] + 1
            if DP[jprim][iprim][k - 1] > val:
                DP[jprim][iprim][k - 1] = val
                way[jprim][iprim][k - 1] = 1
ans = []

i = n
j = m
k = 0
while i != 0 or j != 0 or k != 0:
    c = way[j][i][k]
    ans.append(c)
    val = DP[j][i][k] - 1
    k += 1 - 2 * (c == 0)

    matchi = +(i > 0 and A[i - 1] == c)
    matchj = +(j > 0 and B[j - 1] == c)
    
    if DP[j][i][k] == val:
        pass
    elif matchi and DP[j][i - 1][k] == val:
        i -= 1
    elif matchj and DP[j - 1][i][k] == val:
        j -= 1
    else:
        i -= 1
        j -= 1

print ''.join('(' if x == 0 else ')' for x in reversed(ans))