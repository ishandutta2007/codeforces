import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1
    P = [int(x) for x in inp[ii: ii + m]]; ii += m

    fails = [0]*n
    for p in P:
        fails[p - 1] += 1
    fails[-1] += 1

    summa = 0
    cumsum = []
    for f in reversed(fails):
        summa += f
        cumsum.append(summa)
    cumsum.reverse()

    presses = [0]*26
    for i in range(n):
        presses[ord(S[i]) - ord('a')] += cumsum[i]
    print ' '.join(str(x) for x in presses)