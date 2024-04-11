import sys,io,os,__pypy__
range = xrange
input = raw_input

sys.stdin = io.BytesIO(os.read(0, os.fstat(0).st_size))
n,m = [int(x) for x in input().split()]
A = ''.join(input().strip() for _ in range(n))


UP = [0]*n*m
DO = [0]*n*m
LE = [0]*n*m
RI = [0]*n*m
for y in range(n):
    if A[y*m]=='*':
        RI[y*m]=1
    for x in range(1,m):
        if A[y*m+x]=='*': 
            RI[y*m+x] = RI[y*m + x - 1]+1
for y in range(n):
    if A[y*m + m-1]=='*':
        LE[y*m + m-1]=1
    for x in reversed(range(m-1)):
        if A[y*m+x]=='*': 
            LE[y*m+x] = LE[y*m + x + 1]+1

for x in range(m):
    if A[x]=='*':
        UP[x]=1
    for y in range(1,n):
        if A[y*m+x]=='*': 
            UP[y*m+x] = UP[y*m + x - m]+1
for x in range(m):
    if A[x+(n-1)*m]=='*':
        DO[x+(n-1)*m]=1
    for y in reversed(range(n-1)):
        if A[y*m+x]=='*': 
            DO[y*m+x] = DO[y*m + x + m]+1
STAR = [min(DO[ind],UP[ind],LE[ind],RI[ind]) for ind in range(n*m)]
STAR = [0 if s<=1 else s for s in STAR]

#for y in range(n):
#    print STAR[y*m:(y+1)*m]
#UP = [0]*n*m
#DO = [0]*n*m
#LE = [0]*n*m
#RI = [0]*n*m
for y in range(n):
    RI[y*m]=STAR[y*m]
    for x in range(1,m):
        RI[y*m+x] = max(RI[y*m + x - 1]-1,STAR[y*m+x])
for y in range(n):
    LE[y*m+m-1]=STAR[y*m+m-1]
    for x in reversed(range(m-1)):
        LE[y*m+x] = max(LE[y*m + x + 1]-1,STAR[y*m+x])
for x in range(m):
    DO[x]=STAR[x]
    for y in range(1,n):
        DO[y*m+x] = max(DO[y*m + x - m]-1,STAR[y*m+x])
for x in range(m):
    UP[x+(n-1)*m]=STAR[x+(n-1)*m]
    for y in reversed(range(n-1)):
        UP[y*m+x] = max(UP[y*m + x + m]-1,STAR[y*m+x])


for ind in range(n*m):
    if A[ind]=='*' and not (DO[ind]>0 or UP[ind]>0 or LE[ind]>0 or RI[ind]>0):
        print -1
        sys.exit()

C = __pypy__.builders.StringBuilder()
c = 0
for y in range(n):
    for x in range(m):
        if STAR[x+m*y]>0:
            C.append('%d %d %d\n'%(y+1,x+1,STAR[x+y*m]-1))
            c+=1

print c
print C.build()