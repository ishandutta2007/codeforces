import sys
import bisect
import os

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0

n = inp[ii]; ii += 1
C = inp[ii: ii + n]; ii += n

def reduce(x, B):
    for b in B:
        x = min(x ^ b, x)
    return x

memory = []
maxxors = []

when = []
basis = []
for i in range(n):
    c = C[i]
    
    if c:
        basis = [c]
        for j in reversed(when):
            a = reduce(C[j], basis)
            if a:
                basis.append(a)
            else:
                del when[bisect.bisect_left(when, j)]
        
        bisect.insort_left(when, i)
    
    memory.append(when[:])
    maxxor = [0]
    for b in basis:
        maxxor.append(max(maxxor[-1] ^ b, maxxor[-1]))
    maxxors.append(maxxor)

q = inp[ii]; ii += 1
L = inp[ii + 0: ii + 2 * q: 2]
R = inp[ii + 1: ii + 2 * q: 2]

out = []
for qind in range(q):
    l = L[qind] - 1
    r = R[qind] - 1

    ind = len(memory[r]) - bisect.bisect_left(memory[r], l)
    out.append(maxxors[r][ind])

os.write(1, b'\n'.join(str(x).encode('ascii') for x in out))