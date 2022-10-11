import sys
range = xrange
input = raw_input

import os
inp = os.read(0, 10**6 + 20)

j = 0
while inp[j] >= '0':
    j += 1

j += 2

n = int(inp[:j])
 
A = [0] * (n + 10)
counter = [0] * (n + 10)
S = [-1] * (n + 10) 

ans = []
i = 0
for k in range(n):
    c = inp[k + j]
    if c == 'R':
        i += 1
    elif c == 'L':
        i -= (i != 0)
    elif c == '(':
        S[i] = 0
    elif c == ')':
        S[i] = 1
    else:
        S[i] = -1
            
    l = A[i - 1]
    if l >= 0:
        lc = counter[i - 1]
        if S[i] == 0:
            l += 1
        elif S[i] == 1:
            lc = max(lc, l)
            l -= 1
        counter[i] = lc
    A[i] = l
 
    r = A[i + 2]
    if r >= 0:
        rc = counter[i + 2]
        if S[i + 1] == 1:
            r += 1
        elif S[i + 1] == 0:
            rc = max(rc, r)
            r -= 1
        counter[i + 1] = rc
    A[i + 1] = r
    ans.append(max(l, lc, rc) if l == r >= 0 else -1)
 
os.write(1,' '.join(str(x) for x in ans))