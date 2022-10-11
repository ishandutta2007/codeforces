import sys
range = xrange
input = raw_input

orda = ord('a')

inp = sys.stdin.read().split(); ii = 0

out = []
q = int(inp[ii]); ii += 1
for _ in range(q):
    n = int(inp[ii]); ii += 1

    A = [ord(c) - orda for c in inp[ii]]; ii += 1
    B = [ord(c) - orda for c in inp[ii]]; ii += 1

    countA = [0]*30
    countB = [0]*30
    for a in A:
        countA[a] += 1
    for b in B:
        countB[b] += 1

    if any(c > 1 for c in countA) or any(c > 1 for c in countB):
        out.append(+(countA == countB))
        continue
    if countA != countB:
        out.append(0)
        continue
    
    par = 0
    for i in range(n):
        for j in range(i):
            par ^= (A[j] > A[i]) ^ (B[j] > B[i])
    out.append(1 - par)

print '\n'.join('YES' if o else 'NO' for o in out)