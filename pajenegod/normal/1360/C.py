
import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    n = inter()
    A = inters()
    A.sort()
    
    oddcount = 0
    evencount = 0
    for a in A:
        if a & 1:
            oddcount += 1
        else:
            evencount += 1
    
    if oddcount & 1:
        for i in range(n - 1):
            if A[i] + 1 == A[i + 1]:
                print 'YES'
                break
        else:
            print 'NO'
    else:
        print 'YES'