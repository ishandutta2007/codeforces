#!/usr/bin/python

from sys import stdin

def f(x):
   return sum(map(int, list(str(x))))


def fsum(x):
    n = len(str(x))
    res = 0
#    res2 = sum([f(i) for i in range(x+1)])
    for i in range(n)[::-1]:
        a = x // 10**i
        if i:
           res += a * (45 * 10**(i-1) * i)
        x = x - a * 10**i
        res += a * (a - 1) // 2 * 10**i
        res += (x + 1) * a
    return res;
#    print res, res2
#    assert(res == res2)

def lb(val):
    l = 0
    r = val + 1
    while r - l > 1:
        m = (l + r) // 2
        if fsum(m) < val:
            l = m
        else:
            r = m
    return l


magic = 1000

anss = [-1] * magic
anss[0] = 0

a = int(stdin.read())

x = 1

while True:
    val = fsum(x)
    if val % a >= magic:
       nval = val + (a - val % a)
       x = lb(nval) + 1
       continue
    val = val % a
    if anss[val] != -1:
       print anss[val]+1, x
#       assert((fsum(x) - fsum(anss[val])) % a == 0)
       break
    else:
       anss[val] = x
    x = x + 1