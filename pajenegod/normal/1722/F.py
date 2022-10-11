import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,m = [int(x) for x in input().split()]
    mat = [input().rstrip() for _ in range(n)]

    found = [[0] * m for _ in range(n)]
    for i in range(n):
        icopy = i
        for j in range(m):
            i = icopy
            if found[i][j] or mat[i][j] == '.':
                continue
            
            bfs = [(i,j)]
            found[i][j] = 1
            for i,j in bfs:
                for di,dj in (1,0),(0,1),(-1,0),(0,-1), (1,1),(1,-1),(-1,1),(-1,-1):
                    i2 = i + di
                    j2 = j + dj
                    if 0 <= i2 < n and 0 <= j2 < m and not found[i2][j2] and mat[i2][j2] == '*':
                        found[i2][j2] = 1
                        bfs.append((i2, j2))
            
            I = [i for i,j in bfs]
            J = [j for i,j in bfs]

            if len(bfs) != 3 or max(I) - min(I) != 1 or max(J) - min(J) != 1:
                print('NO')
                break
        else:
            continue
        break
    else:
        print('YES')