import sys
sys.setrecursionlimit(1000000)
input = raw_input
range = xrange

n,m = [int(x) for x in input().split()]

coupl = [[] for _ in range(n)]
doupl = [[] for _ in range(n)]
C = {}
for _ in range(m):
    a,b,c = input().split()
    a = int(a)-1
    b = int(b)-1
    c = ord(c)-ord('a')
    coupl[a].append(b)
    doupl[a].append(c)

opt = [[[-1]*27 for _ in range(n)] for _ in range(n)]
def opti(i,j,k):
    if opt[i][j][k]==-1:
        for X in range(len(coupl[i])):
            nei = coupl[i][X]
            c = doupl[i][X]
            if c>=k and opti(j,nei,c)==0:        
                opt[i][j][k] = 1
                return 1
        opt[i][j][k] = 0
        return 0
    return opt[i][j][k]

VALS = [['A']*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if opti(i,j,0)==0:
            VALS[i][j] = 'B'
    print ''.join(VALS[i])