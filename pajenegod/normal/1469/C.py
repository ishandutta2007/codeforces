import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
    km1 = k - 1
    H = inp[ii: ii + n]; ii += n
    
    l = r = H[0]

    for i in range(1, n):
        h = H[i]
        
        l = max(l - km1, h)
        r = min(r + km1, h + km1)

        if l > r:
            break
    if l <= H[-1] <= r:
        print 'YES'
    else:
        print 'NO'