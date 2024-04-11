import sys
range = xrange
input = raw_input

tran = [0]*1000
tran[ord('A')] = 0
tran[ord('G')] = 1
tran[ord('C')] = 2
tran[ord('T')] = 3

inv = ['A','G','C','T']

h,w = [int(x) for x in input().split()]
A = [[tran[ord(c)] for c in inp] for inp in sys.stdin.read().splitlines()]

comb = []
for i in range(4):
    for j in range(4):
        if i!=j:
            comb.append((i,j))
working = [[] for _ in range(12)]
for i in range(12):
    a,b = comb[i]
    for j in range(12):
        c,d = comb[j]
        if a!=c and a!=d and b!=c and b!=d:
            working[i].append(j)

opt = h*w+1
for rot in [False,True]: 
    if rot:
        B = [[0]*h for _ in range(w)]
        for x in range(w):
            for y in range(h):
                B[x][y] = A[y][x]
        h,w,A = w,h,B

    cost = [[0]*h for _ in range(12)]

    for i in range(12):
        for y in range(h):
            alt = comb[i]
            c = 0
            for x in range(w):
                if A[y][x]!=alt[x%2]:
                    c += 1
            cost[i][y] = c

    DP = [[0]*h for _ in range(12)]
    color = [-1]*h
    for i in range(12):
        DP[i][0] = cost[i][0]

    for y in range(1,h):
        for i in range(12):
            DP[i][y] = min(DP[j][y-1] for j in working[i]) + cost[i][y]
    
    score = min(DP[i][-1] for i in range(12))
    color[-1] = min(range(12),key=lambda i: DP[i][-1])
    for y in reversed(range(1,h)):
        i = color[y]
        for j in working[i]:
            if DP[j][y-1]+cost[i][y]==DP[i][y]:
                color[y-1] = j
                break

    if score<opt:
        opt = score
        opt_color = color
        opt_rot = rot
        opt_h = h
        opt_w = w

C = []
for y in range(opt_h):
    alt = comb[opt_color[y]]
    C.append([alt[x%2] for x in range(opt_w)])


if opt_rot:
    B = [[0]*opt_h for _ in range(opt_w)]
    for x in range(opt_w):
        for y in range(opt_h):
            B[x][y] = C[y][x]
    opt_h,opt_w,C = opt_w,opt_h,B
    opt_rot = False

print '\n'.join(''.join(inv[c] for c in C[y]) for y in range(opt_h))