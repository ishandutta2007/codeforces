import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = [x - 1 for x in inp[ii: ii + n]]; ii += n
B = [x - 1 for x in inp[ii: ii + n]]; ii += n

mapper = [0]*n
for i in range(n):
    mapper[B[i]] = i

score = [0]*n
for i in range(n):
    j = mapper[A[i]]
    score[i - j] += 1

print max(score)