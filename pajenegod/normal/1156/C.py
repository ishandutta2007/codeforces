import sys
range = xrange
input = raw_input

n,z = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()


a = 0
b = n//2
while a<b:
    mid = (a+b+1)//2

    if all(A[-mid+ind] - A[ind]>=z for ind in range(mid)):
        a = mid
    else:
        b = mid-1


print a