import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n
 
best = 0
for i in range(n):
    for j in range(i, n):
        x = A[i] | A[j]
        for k in range(j, n):
            y = x | A[k]
            if y > best:
                best = y
print best