import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a = list(input())
    b = list(input())
    c = list(input())

    n = len(a)
    for i in range(n):
        if a[i] == c[i]:
            b[i] = c[i]
        else:
            a[i] = c[i]

    print 'YES' if a == b else 'NO'