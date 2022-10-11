import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

inp = [int(x) for x in sys.stdin.read().split()]

A = inp[:n*m]
B = inp[n*m:]

for diag in range(n+m-1):
    in_A_minus_B = di(int) 
    for x in range(min(m,diag+1)):
        y = diag-x
        if y<0 or y>=n:continue

        in_A_minus_B[A[x+y*m]] += 1
        in_A_minus_B[B[x+y*m]] -= 1
    for val in in_A_minus_B:
        if in_A_minus_B[val]!=0:
            print 'NO'
            sys.exit()
print 'YES'