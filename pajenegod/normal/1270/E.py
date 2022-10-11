import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

X = inp[ii + 0: ii + 2 * n: 2]
Y = inp[ii + 1: ii + 2 * n: 2]
ii += 2 * n

split = []
while True:
    A = [[[] for _ in range(2)] for _ in range(2)]
    for i in range(n):
        A[X[i]%2][Y[i]%2].append(i)
    if sum(+bool(b) for a in A for b in a) > 1:
        if (A[0][0] or A[1][1]) and (A[0][1] or A[1][0]):
            split += A[0][0]
            split += A[1][1]
        else:
            split = A[0][0] or A[0][1] or A[1][0] or A[1][1]
        break
    X = [x >> 1 for x in X]
    Y = [y >> 1 for y in Y]

print len(split)
print ' '.join(str(x + 1) for x in split)


#00-11 2
#01-10 2
#00 01 1
#00 10 1