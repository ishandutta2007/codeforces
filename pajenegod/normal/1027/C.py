import sys
range = xrange
input = sys.stdin.readline

q = int(input())
out = []

for _ in range(q):
    n = int(input())
    A = [int(x) for x in input().split()]
    A.sort()
    B = []
    i = 0
    while i+1<n:
        while i+1<n and A[i]!=A[i+1]:
            i+=1
        if i+1<n:
            B.append(A[i])
            i+=2
    m = len(B)
    minj = 0 
    for j in range(m-1):
        if B[j]*B[j+1]*(B[minj]**2+B[minj+1]**2)>B[minj]*B[minj+1]*(B[j]**2 + B[j+1]**2):
            minj = j
    
    out.append('%d %d %d %d'%(B[minj],B[minj],B[minj+1],B[minj+1]))

print '\n'.join(out)