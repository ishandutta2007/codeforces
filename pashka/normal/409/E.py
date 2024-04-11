from math import hypot

__author__ = 'Pavel Mavrin'

rr = float(input())
min = 1e100
res = []

for a in range(1, 11):
    for h in range(1, 11):
        x = a / 2
        y = h
        r = x * y / hypot(x, y)
        d = abs(r - rr)
        if d < min:
            min = d
            res = [a, h]

print(*res)