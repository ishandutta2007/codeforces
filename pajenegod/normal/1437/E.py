import sys
range = xrange
input = raw_input

from bisect import bisect_right as binary_search

def LIS(A):
    n = len(A)

    big = 2 * 10**9

    D = [big] * (n + 1)
    D[0] = -big

    for a in A:
        j = binary_search(D, a)
        D[j] = a

    for i in reversed(range(n + 1)):
        if D[i] < big:
            return i

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
k = inp[ii]; ii += 1

A = inp[ii: ii + n]; ii += n
A.insert(0, -10**9)
A.append(10**9 + 2 * n)
n += 2
A = [A[i] - i for i in range(n)]

B = inp[ii: ii + k]; ii += k
B.insert(0,0)
B.append(n - 1)
k += 2

if sorted(A[b] for  b in B) != [A[b] for b in B]:
    print -1
    sys.exit()

ind = -10**9 - 1

for j in range(k - 1):
    b1 = B[j]
    b2 = B[j + 1]

    for i in range(b1 + 1, b2):
        if not (A[b1] <= A[i] <= A[b2]):
            A[i] = ind
            ind -= 1
print n - LIS(A)