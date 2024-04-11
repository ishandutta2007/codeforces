import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

def solve(coupl, Diff):
    n = len(coupl)
    
    color = [-1] * n
    for root in range(n):
        if color[root] != -1:
            continue

        bfs = [root]
        color[root] = 1
        for node in bfs:
            for nei in coupl[node]:
                if color[nei] == -1:
                    color[nei] = 0
                    bfs.append(nei)
                color[nei] |= color[node] ^ 0b11

        if any(color[node] == 0b11 for node in bfs):
            if sum(Diff[node] for node in bfs) & 1:
                return False
        else:
            sum1 = sum(Diff[node] for node in bfs if color[node] == 1)
            sum2 = sum(Diff[node] for node in bfs if color[node] == 2)
            if sum1 != sum2:
                return False
    return True

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1

    V = inp[ii: ii + n]; ii += n
    T = inp[ii: ii + n]; ii += n

    Diff = [V[node] - T[node] for node in range(n)]

    coupl = [[] for _ in range(n)]
    for _ in range(m):
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        coupl[u].append(v)
        coupl[v].append(u)
    
    if solve(coupl, Diff):
        print 'YES'
    else:
        print 'NO'