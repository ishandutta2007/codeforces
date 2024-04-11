import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())

    if n == 2:
        print -1
    else:
        mat = []
        for i in range(n):
            row = list(range(i * n, (i + 1) * n))
            row = [a + 1 for a in row]
            mat.append(row)
        
        for j in range(1,n,2):
            B = [mat[i][j] for i in range(n)]
            for i in range(n):
                mat[i][j] = B[i - 1]
        
        for row in mat:
            print ' '.join(str(x) for x in row)