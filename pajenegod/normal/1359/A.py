import sys
range = xrange

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

def rint():
    global ii
    i = ii
    ii += 1
    return inp[i]

def rints(n):
    global ii
    i = ii
    ii += n
    return inp[i:ii]

def rintss(n, k):
    global ii
    i = ii
    ii += n * k
    return [inp[i + j: ii: k] for j in range(k)]

t = rint()
for _ in range(t):
    n,m,k = rints(3)

    ans = -1
    x = min(m, n//k)
    m -= x
    for y in range(m + 1):
        if y * (k - 1) >= m:
            ans = max(ans, x - y)
    print ans