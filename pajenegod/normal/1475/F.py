import sys
range = xrange
input = sys.stdin.read().split()[::-1].pop

def checker(n):
    A = []
    for _ in range(n):
        row = [ord(x) - 48 for x in input()]
        A.append(row)
    
    if A[0][0]:
        for i in range(n):
            for j in range(n):
                A[i][j] ^= 1
    
    for i in range(1,n):
        if A[i][0]:
            for j in range(n):
                A[i][j] ^= 1
    
    for j in range(1,n):
        if A[0][j]:
            for i in range(n):
                A[i][j] ^= 1
    return A

t = int(input())
for _ in range(t):
    n = int(input())
    
    print 'YES' if checker(n) == checker(n) else 'NO'