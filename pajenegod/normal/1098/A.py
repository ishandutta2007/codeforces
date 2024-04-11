import sys
range = xrange
input = raw_input

n = int(input())
P = [0] + [int(x)-1 for x in input().split()]
S = [int(x) for x in input().split()]

big = 10**18

X = [big]*n
for i in range(n):
    if S[i]>=0:
        X[P[i]] = min(X[P[i]],S[i])

X = [x if x!=big else -1 for x in X]

S = [S[i] if S[i]>=0 else X[i] for i in range(n)]

for i in range(n):
    if S[i]<0:
        S[i] = S[P[i]]

A = [S[i]-S[P[i]] for i in range(n)]
A[0] = S[0]

if any(a<0 for a in A):
    print -1
else:
    print sum(A)