import sys
from collections import defaultdict
range = xrange
input = raw_input

n = int(input())
inp = sys.stdin.read().replace('/','!').split(); ii = 0


inp.sort(reverse=True)

blocks = defaultdict(list)

while ii < n:
    s = inp[ii]
    i = 0
    slashcount = 0
    while i < len(s):
        slashcount += s[i] == '!'
        if slashcount == 3:
            break
        i += 1

    paths = []
    while ii < n and s[:i] == inp[ii][:i]:
        path = inp[ii][i:]
        paths.append(path)
        ii += 1

    blocks[tuple(set(paths))].append(s[:i])


blocks = [blocks[paths] for paths in blocks if len(blocks[paths]) > 1]

print len(blocks)
print '\n'.join(' '.join(hostnames) for hostnames in blocks).replace('!','/')