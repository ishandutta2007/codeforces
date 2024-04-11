import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

def mapper(A):
    B = []
    for c in A:
        if c == '.':
            B.append(0)
        elif c == '#':
            B.append(1)
        elif c == 'G':
            B.append(2)
        else: # c == 'B'
            B.append(3)
    return B

def solve(n,m,A):
    for y in range(n):
        for x in range(m):
            ind = y * m + x
            if A[ind] == 3:
                
                ind2 = ind - 1
                if x:
                    if A[ind2] == 2:
                        return False
                    if A[ind2] == 0:
                        A[ind2] = 1
                
                ind2 = ind + 1
                if x + 1 < m:
                    if A[ind2] == 2:
                        return False
                    if A[ind2] == 0:
                        A[ind2] = 1
                
                ind2 = ind - m
                if y:
                    if A[ind2] == 2:
                        return False
                    if A[ind2] == 0:
                        A[ind2] = 1
                
                ind2 = ind + m
                if y + 1 < n:
                    if A[ind2] == 2:
                        return False
                    if A[ind2] == 0:
                        A[ind2] = 1
    found = [0]*(n*m)
    bfs = [n*m - 1]
    for ind in bfs:
        if found[ind] or A[ind] == 1:
            continue
        found[ind] = 1
        y,x = divmod(ind, m)
        ind2 = ind - 1
        if x:
            bfs.append(ind2)
        
        ind2 = ind + 1
        if x + 1 < m:
            bfs.append(ind2)
        
        ind2 = ind - m
        if y:
            bfs.append(ind2)
        
        ind2 = ind + m
        if y + 1 < n:
            bfs.append(ind2)
    return all(found[ind] for ind in range(n * m) if A[ind] == 2)

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1

    A = []
    for _ in range(n):
        A += mapper(inp[ii]); ii += 1

    print 'Yes' if solve(n,m,A) else 'No'