import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

def issorted(A):
    for i in range(len(A)-1):
        if A[i]>A[i+1]: return False
    return True

A = [[int(x) for x in input().split()] for _ in range(n)]

Acopy = [a[:] for a in A]

for upsidedown in [False, True]:
    if upsidedown:
        A = [a[::-1] for a in Acopy[::-1]]

    # Try make first row and col 0
    inverter_row = [A[i][0] for i in range(n)]
    B = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            B[i][j] = A[i][j]^inverter_row[i]
    A = B
    inverter_col = [x for x in A[0]]
    B = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            B[i][j] = A[i][j]^inverter_col[j]
    A = B

    if n == 1:
        print 'YES'
        print ''.join(str(x) for x in inverter_row)
        print ''.join(str(x) for x in inverter_col)
        sys.exit()

    small = True
    for i in range(1,n):
        if not issorted(A[i]): break

        is0 = all(a==0 for a in B[i])
        mixed = not is0

        if small:
            if mixed:
                small = False
        else:
            if is0:
                inverter_row[i] ^= 1
                A[i] = [1-a for a in A[i]]
            elif mixed:
                break
    else:
        if upsidedown:
            inverter_row = inverter_row[::-1]
            inverter_col = inverter_col[::-1]
            inverter_row = [1-x for x in inverter_row]
        print 'YES'
        print ''.join(str(x) for x in inverter_row)
        print ''.join(str(x) for x in inverter_col)
        sys.exit()
        
print 'NO'