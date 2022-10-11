import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    if sum(A) & 1:
        print 'YES'
    elif any(a&1 for a in A) and any(a&1==0 for a in A):
        print 'YES'
    else:
        print 'NO'