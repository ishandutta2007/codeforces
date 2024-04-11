import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

inds = sorted(range(n), key = A.__getitem__)

B = [A[i] for i in inds]


diff = [B[i + 1] - B[i] for i in range(n - 1)]

DP = [0]*n
P = [-1]*n
for i in range(3,n):
    alt1 = diff[i-1] + DP[i - 3]
    alt2 = DP[i - 1]
    if alt1 > alt2:
        DP[i] = alt1
        P[i] = i - 3
    else:
        DP[i] = alt2
        P[i] = i - 1

i = n - 3
cuts = []
while i >= 0:
    if P[i] == i - 3 >= 0:
        cuts.append(i)
    i = P[i]
cuts.reverse()

i = 0
teams = [len(cuts) + 1]*n
for j in range(len(cuts)):
    c = cuts[j]
    for ind in range(i, c):
        teams[ind] = j + 1
    i = c

C = [0]*n
for i in range(n):
    C[inds[i]] = teams[i]

print B[-1] - B[0] - DP[-3], len(cuts) + 1
print ' '.join(str(x) for x in C)