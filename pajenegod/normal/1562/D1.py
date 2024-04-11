import sys

inp = sys.stdin.read().split(); ii = 0
out = []


t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    q = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1
    A = [1 if (S[i] == '+') ^ (i & 1) else -1 for i in range(n)]
    
    cumsum = [0]
    for a in A:
        cumsum.append(cumsum[-1] + a)

    for _ in range(q):
        l = int(inp[ii]) - 1; ii += 1
        r = int(inp[ii]); ii += 1

        x = abs(cumsum[r] - cumsum[l])
        if x == 0:
            out.append(0)
        elif x & 1:
            out.append(1)
        else:
            out.append(2)

print '\n'.join(str(x) for x in out)