import sys
input = sys.stdin.readline


t = int(input())
for _ in range(t):
    n,m = [int(x) for x in input().split()]
    A = [input()[:-1] for _ in range(n)]
    
    out = [[0]*m for _ in range(n)]
    
    for j in range(m):
        i = n - 1
        while i >= 0:
            while i >= 0 and A[i][j] == 'o':
                i -= 1
            if i < 0:
                break
            ii = i
            count = 0
            while ii >= 0 and A[ii][j] != 'o':
                count += A[ii][j] == '*'
                ii -= 1

            for block in range(count):
                out[i - block][j] = 1
            i = ii

    for i in range(n):
        row = []
        for j in range(m):
            if out[i][j]:
                row.append('*')
            else:
                row.append('o' if A[i][j] == 'o' else '.')
        print(''.join(row))
    print()