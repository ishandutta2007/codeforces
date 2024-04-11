import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    n = inter()
    A = [[int(x) for x in input()] for _ in range(n)]

    for s in range(2 * n - 1):
        for x in range(max(0, s - (n - 1)), min(s + 1, n)):
            y = s - x
            if x + 1 == n or A[y][x + 1] or y + 1 == n or A[y + 1][x]:
                A[y][x] = 0

    if any(any(a) for a in A):
        print 'NO'
    else:
        print 'YES'