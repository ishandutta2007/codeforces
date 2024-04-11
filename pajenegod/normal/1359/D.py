import sys
range = xrange

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

def rint():
    global ii
    i = ii
    ii += 1
    return inp[i]

def rints(n):
    global ii
    i = ii
    ii += n
    return inp[i:ii]

def rintss(n, k):
    global ii
    i = ii
    ii += n * k
    return [inp[i + j: ii: k] for j in range(k)]


def solve(A):
    n = len(A)
    prefixsum = [0]
    for a in A:
        prefixsum.append(prefixsum[-1] + a)
    prefixmin = [0]
    for _ in range(n):
        prefixmin.append(min(prefixmin[-1], prefixsum[_ + 1]))

    best = 0
    for r in range(1, n + 1):
        best = max(best, prefixsum[r] - prefixmin[r])
    return best


n = rint()
A = rints(n)

best = 0
for keep in range(1, 30 + 1):
    i = 0
    while i < n and A[i] > keep:
        i += 1

    while i < n:
        j = i
        while j < n and A[j] <= keep:
            j += 1
        
        best = max(best, solve(A[i:j]) - keep)

        i = j
        while i < n and A[i] > keep:
            i += 1

print best