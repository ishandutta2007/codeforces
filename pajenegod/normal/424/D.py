import sys
range = xrange
input = raw_input
 
inp = map(int, sys.stdin.read().split())
ii = 0
 
n = inp[ii]
ii += 1
m = inp[ii]
ii += 1
t = inp[ii]
ii += 1
 
tp,tu,td = inp[ii:ii+3]
ii += 3
T = [tp, tu, td]
 
A = []
for _ in range(n):
    A.append(inp[ii:ii+m])
    ii += m
 
D = [[0]*m for _ in range(n - 1)]
U = [[0]*m for _ in range(n - 1)]
for y in range(n - 1):
    Dy = D[y]
    Uy = U[y]
    Ay = A[y]
    Ayp1 = A[y + 1]
    for x in range(m):
        Dy[x] = T[(Ay[x] <= Ayp1[x]) - (Ay[x] >= Ayp1[x])]
        Uy[x] = T[(Ay[x] >= Ayp1[x]) - (Ay[x] <= Ayp1[x])]
 
L = [[0]*(m - 1) for _ in range(n)]
R = [[0]*(m - 1) for _ in range(n)]
for y in range(n):
    Ly = L[y]
    Ry = R[y]
    Ay = A[y]
    for x in range(m - 1):
        Ry[x] = T[(Ay[x] <= Ay[x + 1]) - (Ay[x] >= Ay[x + 1])]
        Ly[x] = T[(Ay[x] >= Ay[x + 1]) - (Ay[x] <= Ay[x + 1])]
 
Dcum = [[0]*m for _ in range(n)]
Ucum = [[0]*m for _ in range(n)]
Lcum = [[0]*m for _ in range(n)]
Rcum = [[0]*m for _ in range(n)]
 
for y in range(n):
    Lcumy = Lcum[y]
    Ly = L[y]
    Rcumy = Rcum[y]
    Ry = R[y]
    for x in reversed(range(m - 1)):
        Lcumy[x] = Lcumy[x + 1] + Ly[x]
        Rcumy[x] = Rcumy[x + 1] + Ry[x]
 
 
for y in reversed(range(n - 1)):
    Ucumy = Ucum[y]
    Ucumyp1 = Ucum[y + 1]
    Uy = U[y]
    
    Dcumy = Dcum[y]
    Dcumyp1 = Dcum[y + 1]
    Dy = D[y]
 
 
    for x in range(m):
        Ucumy[x] = Ucumyp1[x] + Uy[x]
        Dcumy[x] = Dcumyp1[x] + Dy[x]
 
besta = 2 * 10**9
bestay1 = -1
bestay2 = -1
bestax1 = -1
bestax2 = -1
 
for y1 in range(n):
    y1besta = besta
 
    Rcumy1 = Rcum[y1]
    Ucumy1 = Ucum[y1]
    Dcumy1 = Dcum[y1]
 
    help1y1 = [Rcumy1[x] + Ucumy1[x] - t for x in range(m)]
    help2y1 = [Rcumy1[x] - Dcumy1[x] for x in range(m)]
 
    for y2 in range(y1 + 2, n):
        y2besta = besta
        
        Lcumy2 = Lcum[y2]
        Ucumy2 = Ucum[y2]
        Dcumy2 = Dcum[y2]
        
        precalc1 = [help1y1[x] + Lcumy2[x] - Ucumy2[x] for x in range(m)]
        precalc2 = [help2y1[x] + Lcumy2[x] + Dcumy2[x] for x in range(m)]

        tmp = []
        
        for x1 in range(m - 2):
            t2 = precalc1[x1]
            a = -1
            b = len(tmp)
            while 1 + a - b:
                c = a + b >> 1
                if tmp[c] < t2:
                    a = c
                else:
                    b = c
            tmp.insert(b, t2)
            
            t3 = precalc2[x1 + 2]
            a = -1
            b = len(tmp)
            while 1 + a - b:
                c = a + b >> 1
                if tmp[c] < t3:
                    a = c
                else:
                    b = c
            
            if b < len(tmp) and tmp[b] - t3 < besta:
                besta = tmp[b] - t3
            if b - 1 >= 0 and t3 - tmp[b - 1] < besta:
                besta = t3 - tmp[b - 1]
        
        if y2besta != besta:
            bestay2 = y2
    if y1besta != besta:
        bestay1 = y1

Rcumy1 = Rcum[bestay1]
Ucumy1 = Ucum[bestay1]
Dcumy1 = Dcum[bestay1]
Lcumy2 = Lcum[bestay2]
Ucumy2 = Ucum[bestay2]
Dcumy2 = Dcum[bestay2]
 
for bestax1 in range(m):
    for bestax2 in range(bestax1 + 2, m):
        val = Rcumy1[bestax1] - Rcumy1[bestax2] + Lcumy2[bestax1] - Lcumy2[bestax2] + Ucumy1[bestax1] - Ucumy2[bestax1] + Dcumy1[bestax2] - Dcumy2[bestax2]
        if abs(val - t) == besta:break
    else:
        continue
    break
 
print bestay1 + 1, bestax1 + 1, bestay2 + 1, bestax2 + 1