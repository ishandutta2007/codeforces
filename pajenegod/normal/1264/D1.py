import sys
range = xrange
input = raw_input

import __pypy__
mulmod = __pypy__.intop.int_mulmod

MOD = 998244353  
half = pow(2, MOD - 2, MOD)

S = input()
n = len(S)
A = []
for c in S:
    if c == '?':
        A.append(0)
    elif c == '(':
        A.append(1)
    else:
        A.append(2)

DPL = [[0]*(n - l + 1) for l in range(n + 1)]
DPR = [[0]*(n - l + 1) for l in range(n + 1)]

for l in range(1, n + 1):
    for x in range(n - l + 1):
        if A[x] == 0:
            DPL[l][x] = mulmod(half, DPR[l - 1][x + 1] + DPL[l - 1][x + 1], MOD)
        elif A[x] == 1:
            DPL[l][x] = DPR[l - 1][x + 1] 
        else:
            DPL[l][x] = DPL[l - 1][x + 1]
    
    for x in range(n - l + 1):
        if A[x + l - 1] == 0:
            DPR[l][x] = mulmod(half, DPR[l - 1][x] + DPL[l - 1][x] + 1, MOD)
        elif A[x + l - 1] == 1:
            DPR[l][x] = DPR[l - 1][x] 
        else:
            DPR[l][x] = DPL[l - 1][x] + 1

print DPL[n][0] * pow(2, sum(1 for a in A if a == 0), MOD) % MOD