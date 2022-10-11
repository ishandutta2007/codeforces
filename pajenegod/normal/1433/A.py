import sys
range = xrange
input = raw_input

A = []
for c in '123456789':
    for n in range(1, 5):
        A.append(int(c * n))

t = int(input())
for _ in range(t):
    x = int(input())
    y = 0
    for a in A:
        y += len(str(a))
        if x == a:
            break
    print y