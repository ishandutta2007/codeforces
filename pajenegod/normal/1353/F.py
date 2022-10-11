import pypyjit
pypyjit.set_param(threshold=100)

import sys
range = xrange
input = raw_input
 
inp = []; ii = 0
S = sys.stdin.read()
N = len(S)
i = 0
c = 0.0
for i in range(N):
    if S[i] >= '0':
        c = 10 * c + ord(S[i]) - 48
    elif S[i] == ' ' or S[i] == '\n':
        inp.append(c)
        c = 0.0
 
intinf = 10**18
inf = 15e14
inf2 = 1e18
 
t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1
 
    A = []
    for _ in range(n):
        A.append(inp[ii: ii + m]); ii += m
 
    for y in range(n):
        for x in range(m):
            A[y][x] -= x + y - (n + m)
 
    B = [[inf2]*m for _ in range(n)]
    def lowest_cost(d,y1,x1,y2,x2):
        dp0 = [200]*(x2 - x1)
        dp1 = [0.0]*(x2 - x1)
        dp0[0] = 0
        for y in range(y2 - y1):
            By = B[y + y1]
            dp1[0] += By[x1]
            if dp1[0] >= inf:
                dp0[0] += 1
                dp1[0] -= inf
            for x in range(1, x2 - x1):
                b = By[x + x1]
                dp0[x], dp1[x] = min((dp0[x], dp1[x]), (dp0[x - 1], dp1[x - 1]))
                if dp1[x] + b >= inf:
                    dp0[x] += 1
                    dp1[x] += b - inf
                else:
                    dp1[x] += b
        return dp0[-1] * int(inf) + int(dp1[-1])
    
    opt = intinf
    indices = [(y,x) for y in range(n) for x in range(m)]
    for y,x in sorted(indices, key = lambda p: A[p[0]][p[1]], reverse = True):
        B[y][x] = d = A[y][x]
        z = lowest_cost(d,0,0,y+1,x+1) + lowest_cost(d,y,x,n,m)
        opt = min(opt, z - int(d) * (n + m))
    print opt