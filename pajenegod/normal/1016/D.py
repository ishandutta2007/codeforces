import sys
range = xrange
input = sys.stdin.readline


n,m = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

C = [[0]*m for _ in range(n)]

val = max(max(A),max(B))
count = 0
while val>0:
    count += 1
    for i in range(n):
        for j in range(m):
            C[i][j]*=2

    for i in range(n):
        if A[i]%2==1: 
            for j in range(m):
                if B[j]%2==1:
                    C[i][j]+=1
                    A[i]-=1
                    B[j]-=1
                    break
    oddA = [i for i in range(n) if A[i]%2==1]
    oddB = [j for j in range(m) if B[j]%2==1]
    if (len(oddA)+len(oddB))%2==1:
        print 'NO'
        sys.exit()
    for i in range(0,len(oddA),2):
        ind1 = oddA[i]
        ind2 = oddA[i+1]
        A[ind1]-=1
        A[ind2]-=1
        C[ind1][0]+=1
        C[ind2][0]+=1
    for j in range(0,len(oddB),2):
        ind1 = oddB[j]
        ind2 = oddB[j+1]
        B[ind1]-=1
        B[ind2]-=1
        C[0][ind1]+=1
        C[0][ind2]+=1
    
    val //=2
    for i in range(n):
        A[i] //= 2
    for j in range(m):
        B[j] //= 2

D = [[0]*m for _ in range(n)]
for _ in range(count):
    for i in range(n):
        for j in range(m):
            D[i][j] *= 2
            D[i][j] += C[i][j]%2
            C[i][j] //= 2

print 'YES'
for i in range(n):
    print ' '.join(str(x) for x in D[i])
    
#    a = 0
#    for val in D[i]:
#        a ^= val
#    print a

#for j in range(m):
#    a = 0
#    for i in range(n):
#        val = D[i][j]
#        a ^= val
#    print a