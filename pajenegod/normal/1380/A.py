import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    for i in range(n - 2):
        if A[i] < A[i + 1] > A[i + 2]:
            print 'Yes'
            print i + 1, i + 2, i + 3
            break
    else:
        print 'No'