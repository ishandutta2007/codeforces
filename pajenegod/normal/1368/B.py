import sys
range = xrange
input = raw_input

S = 'codeforces'

k = int(input())

ways = 1
A = [1] * len(S)
i = 0
while ways < k:
    ways //= A[i]
    A[i] += 1
    ways *= A[i]

    i = (i + 1) % len(S)

out = []
for i in range(len(S)):
    out += S[i] * A[i]
print ''.join(out)