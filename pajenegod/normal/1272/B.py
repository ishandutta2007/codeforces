import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

mapper = {}
for i in range(4):
    mapper['UDLR'[i]] = i

out = []
q = int(inp[ii]); ii += 1
for _ in range(q):
    S = inp[ii]; ii += 1

    counts = [0]*4
    for c in S:
        counts[mapper[c]] += 1

    mini = 0
    s = ''
    if counts[0] > 0 and counts[1] > 0:
        mini = 2
        s = 'UD'
    elif counts[2] > 0 and counts[3] > 0:
        mini = 2
        s = 'LR'

    if all(c > 0 for c in counts):
        a = min(counts[0], counts[1])
        b = min(counts[2], counts[3])
        mini = 2 * a + 2 * b
        s = 'U' * a + 'L' * b + 'D' * a + 'R' * b

    out.append(str(mini))
    out.append(s)
print '\n'.join(out)