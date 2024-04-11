import sys,io,os
from atexit import register
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
sys.stdout = io.BytesIO()
register(lambda :os.write(1,sys.stdout.getvalue()))

visited = [[0]*1002 for _ in range(1002)]
out = [[-1]*1002 for _ in range(1002)]

n , m , k = [int(x) for x in input().split()]
l = [input() for _ in range(n)]
Q = []
for j in range(m):
    for i in range(n):
        if not visited[i][j] and l[i][j] == b'.'[0]:
            c = 0
            Q.append((i,j))
            ind = 0
            while ind<len(Q):
                x,y = Q[ind]
                ind+=1
                if x >= n or x < 0 or y >= m or y < 0:
                    continue
                if l[x][y] == b'*'[0]:
                    c += 1
                    continue
                if visited[x][y] :
                    continue
                visited[x][y] = 1
                Q.append((x+1,y))
                Q.append((x,y+1))
                Q.append((x-1,y))
                Q.append((x,y-1))
            while Q:
                x,y = Q.pop()
                out[x][y] = c
for i in range(k):
    x , y = [int(x) for x in input().split()]
    sys.stdout.write(str(out[x-1][y-1]).encode())
    sys.stdout.write(b'\n')