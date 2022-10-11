import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0
out = []

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    q = int(inp[ii]); ii += 1

    S = inp[ii]; ii += 1

    for _ in range(q):
        l = int(inp[ii]) - 1; ii += 1
        r = int(inp[ii]); ii += 1
        
        for i in range(0, l):
            if S[i] == S[l]:
                break
        else:
            for i in range(r, n):
                if S[i] == S[r - 1]:
                    break
            else:
                out.append(0)
                continue
        out.append(1)

print '\n'.join('YES' if b else 'NO' for b in out)