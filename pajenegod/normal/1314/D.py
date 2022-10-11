import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

mat = [[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        mat[j].append(inp[i*n + j])

inf = 10**9 + 100

def randomer(odd, even):
    best = [inf]*n
    best[0] = 0
    best2 = [inf]*n
    for _ in range(k):
        for j in odd:
            opti = inf
            matj = mat[j]
            for i in even:
                val = best[i] + matj[i]
                if opti > val:
                    opti = val
            best2[j] = opti
        best, best2, odd, even = best2, best, even, odd
    return best[0]

sys.modules["hashlib"] = sys.sha512 = sys
import random
best = inf
for _ in range(10 * 2**k):
    odd = []
    even = [0]
    for _ in range(1, n):
        (odd if random.randint(0,1) else even).append(_) 
    best = min(best, randomer(odd, even))
print best