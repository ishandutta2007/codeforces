import sys
range = xrange
input = sys.stdin.readline

def decode(x):
    A = []
    while x:
        A.append(x % k)
        x //= k
    return A
 
def encode(A):
    s = 0
    for i, a in enumerate(A):
        s += a * k **i
    return s


import os
par = 0
def query(x):
    global par
    par ^= 1
    if not par:
        A = decode(x)
        A = [k - a for a in A]
        x = encode(A)
    os.write(1, str(x) + '\n')
    return int(input()) == 1


def f(i, k):
    if i == 0 and query(0):
        yield True
    nesta = f(i + 1, k)
    while True:
        for _ in range(k - 1):
            if query(sum(k**j for j in range(i + 1))):
                break
            yield
        else:
            if next(nesta):
                break
            yield
            continue
        break
    yield True

t = int(input())
for _ in range(t):
    par = 0
    n,k = [int(x) for x in input().split()]
    
    solve = f(0, k)
    while not next(solve): continue