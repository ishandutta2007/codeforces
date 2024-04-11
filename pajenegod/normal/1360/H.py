import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1
    
    A = [int(x, 2) for x in inp[ii:ii + n]]; ii += n

    k = (1 << m) - n
    goalind = ((k - 1) >> 1) + 1

    a = 0
    b = (1 << m) - 1

    while a < b:
        c = a + b + 1 >> 1
        le = c + 1
        geq = (1 << m) - 1 - c
        for x in A:
            if x < c:
                le -= 1
            else:
                geq += 1
        if le <= goalind:
            a = c
        else:
            b = c - 1
    print bin((1 << m) + a)[3:]