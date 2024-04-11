import sys
range = xrange
input = raw_input

n,m,k = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

pairs = [B[i+1]-B[i]-1 for i in range(n-1)]
pairs.sort(reverse=True)

cost = n
k-=n
while k<0:
    cost += pairs.pop()
    k+=1

print cost