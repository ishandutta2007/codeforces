import sys
range = xrange
input = raw_input

from types import GeneratorType

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

bfs = [0]
for node in bfs:
    for nei in coupl[node]:
        del coupl[nei][coupl[nei].index(node)]
        bfs.append(nei)

tree = []
time = []

@bootstrap
def dfs(i, t = 0):
    tree.append(i)
    time.append(t)

    t0 = t
    deg = len(coupl[i])

    lower = max(min(t - 1, deg), 0)
    upper = deg - lower

    ind = 0
    while ind < len(coupl[i]) and upper:
        yield dfs(coupl[i][ind], t + 1)
        t += 1
        
        tree.append(i)
        time.append(t)

        upper -= 1
        ind += 1
    
    t = t0 - lower - 1

    tree.append(i)
    time.append(t)

    while lower:
        yield dfs(coupl[i][ind], t + 1)
        t += 1
        
        tree.append(i)
        time.append(t)
        
        lower -= 1
        ind += 1
    yield

dfs(0,0)

print len(tree) - 1
print '\n'.join('%d %d' % (tree[i] + 1, time[i]) for i in range(len(tree) - 1))