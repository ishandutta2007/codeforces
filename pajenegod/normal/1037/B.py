import sys
range = xrange
input = sys.stdin.readline

n,s = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()

val = A[n//2]
if val==s:
    print 0
elif val>s:
    print sum(a-s for a in A[:n//2+1] if a>s)
else:
    print sum(s-a for a in A[n//2:] if a<s)