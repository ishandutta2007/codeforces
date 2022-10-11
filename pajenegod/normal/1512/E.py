import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,l,r,s = [int(x) for x in input().split()]
    l -= 1

    s -= r - l

    A = list(reversed(range(r - l)))
    g = sum(A)
    
    i = 0
    while i < r - l and s > g:
        tmp = A[i]

        A[i] = min(n - 1 - i, A[i] + s - g)
        g = g - tmp + A[i]

        i += 1


    if not g == s >= 0:
        print -1
    else:
        unused = set(range(n)) - set(A)
        unused = list(unused)
        
        ans = unused[:l] + A + unused[l:]
        print ' '.join(str(x + 1) for x in ans)