import sys
input = raw_input
range = xrange

n = int(input())
A = [int(x) for x in input().split()]

best1 = [0]*(n+1)
best2 = [0]*(n+1)
best3 = [0]*(n+1)
best4 = [0]*(n+1)

for i in range(n):
    if A[i]==1:
        best1[i] = best1[i-1]+1
    else:
        best1[i] = best1[i-1]
    if A[i]==1:
        best2[i] = max(best2[i-1],best1[i-1])
    else:
        best2[i] = max(best2[i-1]+1,best1[i-1]+1)
    if A[i]==1:
        best3[i] = max(best3[i-1]+1,best2[i-1]+1)
    else:
        best3[i] = max(best3[i-1],best2[i-1])

    if A[i]==1:
        best4[i] = max(best4[i-1],best3[i-1])
    else:
        best4[i] = max(best4[i-1]+1,best3[i-1]+1)
print max([best1[n-1],best2[n-1],best3[n-1],best4[n-1]])