import sys
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    W = [int(x) for x in input().split()]

    A.sort()
    W.sort(reverse=True)
    
    s = sum(A[-k:])
    i = 0
    j = n - 1
    for w in W:
        if w > 1:
            s += A[i]
            i += w - 1
        else:
            s += A[j]
            j -= 1
    print s