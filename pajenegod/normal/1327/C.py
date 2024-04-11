import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
k = inp[ii]; ii += 1

SY = inp[ii + 0: ii + 2 * k: 2]
SX = inp[ii + 1: ii + 2 * k: 2]
ii += 2 * k

GY = inp[ii + 0: ii + 2 * k: 2]
GX = inp[ii + 1: ii + 2 * k: 2]
ii += 2 * k

S = ['L']*(m - 1)
S += ['U']*(n - 1)

for x in range(m):
    if x & 1:
        S += ['U'] * (n - 1)
    else:
        S += ['D'] * (n - 1)
    S.append('R')

print len(S)
print ''.join(S)