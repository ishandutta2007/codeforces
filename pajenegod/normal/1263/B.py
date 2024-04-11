import sys
range = xrange
input = sys.stdin.readline

import sys
sys.modules["hashlib"] = sys.sha512 = sys
import random

t = int(input())

out = []
for _ in range(t):
    n = int(input())
    P = [tuple(int(c) for c in input().rstrip()) for _ in range(n)]
    
    Pset = set(P)

    Q = []
    seen = set()
    for p in P:
        q = p
        if tuple(p) in seen:
            while tuple(p) in Pset or tuple(p) in seen:
                p = list(q)
                i = random.randint(0, 3)
                j = random.randint(0, 9)
                p[i] = j
        Q.append(tuple(p))
        seen.add(tuple(p))
    out.append(str(n - len(Pset)))
    for q in Q:
        out.append(''.join(str(x) for x in q))

print '\n'.join(out)