import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    n = int(input())
    
    P = [int(x) for x in input().split()]
    used = [0]*(n - 1)

    i = 1
    while i <= n:
        j = 0
        while j < n and P[j] != i:
            j += 1
    
        while j > 0 and not used[j - 1] and P[j-1] > P[j]:
            used[j - 1] = 1
            P[j],P[j-1] = P[j-1],P[j]
            j -= 1

        i += 1
    print ' '.join(str(x) for x in P)