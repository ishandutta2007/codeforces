import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
# n duration in min
# k awake

#1<=a<=10**4, len(A)=n
A = [int(x) for x in input().split()]

cumsum = [0]
for a in A:
    cumsum.append(cumsum[-1]+a)
cumsum.append(cumsum[-1])
# 0<=t<=1
T = [int(x) for x in input().split()]

cumsum2 = [0]
for i in range(n):
    if T[i]==1:
        a = A[i]
    else:
        a = 0
    cumsum2.append(cumsum2[-1]+a)
cumsum2.append(cumsum2[-1])
# first index being awake
i = 0
# first index pos sleep
j = k

besta = -1
while j-1<n:
    besta = max(besta,cumsum2[i]+cumsum[j]-cumsum[i]+cumsum2[-1]-cumsum2[j])
    i+=1
    j+=1
print besta