import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    P = inp[ii + 0: ii + 2*n: 2]
    C = inp[ii + 1: ii + 2*n: 2]
    ii += 2*n
    
    P.insert(0,0)
    C.insert(0,0)
    for i in range(1, n + 1):
        dp = P[i] - P[i - 1]
        dc = C[i] - C[i - 1]
        if dp < dc or dp < 0 or dc < 0:
            print 'NO'
            break
    else:
        print 'YES'