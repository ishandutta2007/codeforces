import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]
A.sort()
i = 0
j = 0
besta = -1
while i<n:
    while j<n and A[i]+5>=A[j]:j+=1
    besta = max(besta,j-i)
    i+=1
print besta