import sys
import os
range = xrange
input = raw_input

big = 10**9
ord0 = ord('0')

S = os.read(0, 2**25)

ii = 0
n = 0
while ord(S[ii]) >= ord0:
    n = 10 * n + ord(S[ii]) - ord0
    ii += 1
ii += 1

K = 0
while ord(S[ii]) >= ord0:
    K = 10 * K + ord(S[ii]) - ord0
    ii += 1
ii += 2

mat = [ord(S[ii + 2 * i + j * (2 * n + 1)]) - ord0 for j in range(n) for i in range(n)]

# i - j = k
for k in range(2, n):
    for i in range(k, n):
        j = i - k
        mat[j + i*n] += mat[j +     n*(i - 1)] +        \
                        mat[j + 1 + n*i      ] -             \
                        mat[j + 1 + n*(i - 1)]

best = [mat[n * i] for i in range(n)]
old_best = [0]*n
prev_block_start = [0]*n
prev_block_start.append(n - 2)
old_prev_block_start = list(prev_block_start)

for _ in range(2, K+1):
    best, old_best, prev_block_start, old_prev_block_start = \
    old_best, best, old_prev_block_start, prev_block_start
    for i in reversed(range(n)):
        besta = big
        besta_ind = 0
        for j in range(old_prev_block_start[i],  prev_block_start[i + 1] + 1):
            val = mat[j + 1 + n*i] + old_best[j]
            if val < besta:
                besta = val
                besta_ind = j
        best[i] = besta
        prev_block_start[i] = besta_ind
print best[-1]