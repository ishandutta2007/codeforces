# Not my code
# https://codeforces.com/contest/1416/submission/94027802
import sys,io,os
from collections import defaultdict 
 
inp = [int(x) for x in sys.stdin.buffer.read().split()]
 
n = inp.pop(0)
A = inp
 
t = 0.0
x = 0
for v in range(1, 31)[::-1]:
    u = d = 0.0
    r1 = defaultdict(int)
    r2 = defaultdict(int)
    w = 1 << v - 1
    for a in A:
        p = a >> v
        b = a & w
        if b:
            r1[p] += 1
        elif p in r1:
            d += 2 * r1[p]
        r2[p] += 1
    for p in r2:
        if p in r1:
            rp = r1[p] + 0.0
            cp = r2[p] + 0.0
            u += cp * (cp - 1) - rp * (rp - 1) - (cp - rp) * (cp - rp - 1)
    if d > u - d:
        x += w
        d = u - d
    t += d
print(int(t) // 2, x)