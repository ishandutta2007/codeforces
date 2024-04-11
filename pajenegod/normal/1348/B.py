import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    
    Aset = set(A)
    if len(Aset) > k:
        print -1
    else:
        B = list(Aset) + [1] * (k - len(Aset))
        print len(B) * n
        print ' '.join(str(x) for x in B*n)