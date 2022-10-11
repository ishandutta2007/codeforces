import sys
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    mapper = {}
    for a in sorted(A):
        if a not in mapper:
            mapper[a] = len(mapper)
    
    m = len(mapper)
    A = [mapper[a] for a in A]
    Asorted = sorted(A)

    buckets = [[] for _ in range(m + 1)]
    B = [0] * (m + 2)
    for i in range(n):
        buckets[A[i]].append(i)
        B[A[i] + 1] += 1
    
    for i in range(m + 1):
        B[i + 1] += B[i]
    
    jump = [-1] * m
    for j in reversed(range(m)):
        lasti = buckets[j][-1]
        if j + 1 == m or buckets[j + 1][0] < lasti:
            jump[j] = lasti
        else:
            jump[j] = jump[j + 1]

    best = 0

    prev = -1
    prevcount = -1
    for i in reversed(range(n)):
        b = a = Asorted[i]
        if a != prev:
            prev = a
            prevcount = 1
        else:
            prevcount += 1
        

        ind = buckets[a][prevcount - 1]
        if buckets[a + 1] and buckets[a + 1][0] >= ind:
            ind = jump[a + 1]
            a = A[ind]

        l = 0
        r = len(buckets[a + 1])
        while l < r:
            mid = l + r >> 1
            if buckets[a + 1][mid] < ind:
                l = mid + 1
            else:
                r = mid

        best = max(best, prevcount + B[a + 2] - l - B[b + 1])
    print n - best