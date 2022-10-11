import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1

V = [float(x) for x in inp[ii:ii + n]]; ii += n
C = [c - 1 for c in inp[ii:ii + n]]; ii += n

A = inp[ii::2]
B = inp[ii+1::2]

inf = 1e30

out = []

for _ in range(q):
    a = float(A[_])
    b = float(B[_])

    bestcolor = [-inf]*n
    
    best1 = 0.0
    color1 = -1
    best2 = 0.0

    for i in range(n):
        c = C[i]
        v = V[i]

        x = max(bestcolor[c] + v * a, (best1 if color1 != c else best2) + v * b)
        
        bestcolor[c] = max(bestcolor[c], x)
        if x > best1:
            if color1 != c:
                best2 = best1
            best1 = x
            color1 = c
        elif x > best2 and color1 != c:
            best2 = x
    out.append(best1)
print '\n'.join(str(int(x)) for x in out)