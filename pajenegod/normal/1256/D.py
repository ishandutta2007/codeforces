import sys
range = xrange
input = raw_input

ord0 = ord('0')

inp = sys.stdin.read().split(); ii = 0

out = []
q = int(inp[ii]); ii += 1
for _ in range(q):
    n = int(inp[ii]); ii += 1
    k = int(inp[ii]); ii += 1

    S = [ord(c) - ord0 for c in inp[ii]]; ii += 1

    i = 0
    while i < n and S[i] == 0:
        i += 1

    j = i
    while j < n:
        while j < n and S[j] == 1:
            j += 1

        if j == n:
            break

        dist = min(j - i, k)
        k -= dist
        S[j], S[j - dist] = S[j - dist], S[j]

        if k == 0:
            break
        i += 1

    out.append(''.join(str(c) for c in S))

print '\n'.join(out)