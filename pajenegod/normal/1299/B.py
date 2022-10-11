import sys
range = xrange
input = raw_input

def ans(x):
    if x:
        print 'YES'
    else:
        print 'NO'
    sys.exit()

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
if n & 1:
    ans(False)

X = inp[ii + 0: ii + 2 * n: 2]
Y = inp[ii + 1: ii + 2 * n: 2]
ii += 2 * n

midx = X[0] + X[n//2]
midy = Y[0] + Y[n//2]

for i in range(n//2):
    mx = X[i] + X[i + n//2]
    my = Y[i] + Y[i + n//2]

    if mx != midx or my != midy:
        ans(False)
    d1 = (2 * X[i] - mx)**2 + (2 * Y[i] - my)**2
    d2 = (2 * X[i + n//2] - mx)**2 + (2 * Y[i + n//2] - my)**2
    if d1 != d2:
        ans(False)
ans(True)