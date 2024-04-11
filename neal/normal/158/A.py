_,K=map(int,raw_input().split())
A=map(int,raw_input().split())
print sum(x>=max(A[K-1],1) for x in A)