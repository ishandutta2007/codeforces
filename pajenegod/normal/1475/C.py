import sys
from collections import defaultdict
range = xrange
input = raw_input

def checker(A):
    counter = defaultdict(int)
    for a in A:
        counter[a] += 1

    total = 0
    for a in counter:
        total += counter[a] * (counter[a] - 1) // 2
    return total


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    a = inp[ii]; ii += 1
    b = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
    
    A = inp[ii: ii + k]; ii += k
    B = inp[ii: ii + k]; ii += k

    total = k * (k - 1) // 2 - checker(A) - checker(B)
    print total