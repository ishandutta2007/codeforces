import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    A = set(A)

    i = 1
    while i * i <= 10**4:
        sq = i * i
        if sq in A:
            A.remove(sq)
        i += 1
    if A:
        print 'YES'
    else:
        print 'NO'