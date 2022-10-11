import sys
range = xrange
input = sys.stdin.readline

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

bags = 0
for i in range(n):
    bags += A[i]//k
    A[i]%=k
    if A[i]>0:
        bags += 1
        if i+1<n:
            A[i+1] -= k-A[i]
            if A[i+1]<0:A[i+1]=0
        A[i] = 0
print bags