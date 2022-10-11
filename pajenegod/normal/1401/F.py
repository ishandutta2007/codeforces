import sys
range = xrange
input = raw_input

# Bugs, bugs everywhere

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = 1 << n 
q = inp[ii]; ii += 1

A = inp[ii: ii + m]; ii += m
swapped = [0] * n

B = [0] * (2 * m)
B[m:] = A
for i in reversed(range(1, m)):
    B[i] = B[2 * i] + B[2 * i + 1]

def getter(r):
    if r == m:
        return 2 * m, B[1]

    ind = 1
    s = 0
    for level in range(n):
        jump = 1 << n - 1 - level
        if jump <= r:
            r -= jump
            ind = (2 * ind) ^ swapped[level] ^ 1
            s += B[ind ^ 1]
        else:
            ind = (2 * ind) ^ swapped[level]
    return ind, s

def setter(ind, val):
    ind, _ = getter(ind)
    B[ind] = val
    ind >>= 1
    while ind:
        B[ind] = B[2 * ind] + B[2 * ind + 1]
        ind >>= 1

def getsum(l, r):
    _,lsum = getter(l)
    _,rsum = getter(r)
    return rsum - lsum

out = []
for _ in range(q):
    cas = inp[ii]; ii += 1
    if cas == 1:
        # Replace
        x = inp[ii] - 1; ii += 1
        k = inp[ii]; ii += 1
        
        setter(x, k)
    elif cas == 2:
        # reverse
        k = inp[ii]; ii += 1
        for i in range(k):
            swapped[~i] ^= 1
    elif cas == 3:
        # swap
        k = inp[ii]; ii += 1
        swapped[~k] ^= 1
    elif cas == 4:
        # print sum
        l = inp[ii] - 1; ii += 1
        r = inp[ii]; ii += 1
        out.append(getsum(l,r))
    else:
        assert False

print '\n'.join(str(x) for x in out)