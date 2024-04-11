import sys

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]
    x = a + b + c
    y = b + c
    z = c

    assert x % y == a
    assert y % z == b
    assert z % x == c
    print(x, y, z)