import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

q = inp[ii]
ii += 1

out = []
for _ in range(q):
    c = inp[ii]
    ii += 1
    m = inp[ii]
    ii += 1
    x = inp[ii]
    ii += 1

    y = min(c,m)
    x += c - y + m - y
    
    a = 0
    b = 10**8 + 10
    while a < b:
        mid = a + b + 1 >> 1
        if y >= mid and x + 2*(y - mid) >= mid:
            a = mid
        else:
            b = mid - 1    
    out.append(a)
print '\n'.join(str(x) for x in out)