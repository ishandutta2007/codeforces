import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

q = inp[ii]; ii += 1
ans = []
for _ in range(q):
    n = inp[ii]; ii += 1
    r = inp[ii]; ii += 1
    X = inp[ii:ii + n]; ii += n
    X.sort()
    blaster = 0
    moves = 0
    while X and X[-1] - blaster > 0:
        x = X[-1]
        while X and x == X[-1]:
            X.pop()
        blaster += r
        moves += 1

    ans.append(moves)
print '\n'.join(str(x) for x in ans)