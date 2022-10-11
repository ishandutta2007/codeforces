import sys
range = xrange
input = sys.stdin.readline

def query(A):
    print '?', len(A), ' '.join(str(a + 1) for a in A) 
    sys.stdout.flush()
    x,d = [int(x) for x in input().split()]
    return x - 1, d

def ans(x0, x1):
    print '!', x0 + 1, x1 + 1
    sys.stdout.flush()
    input()

def bfser(root, coupl):
    n = len(coupl)
    
    bfs = [root]
    depth = [-1] * n
    depth[root] = 0
    for node in bfs:
        for nei in coupl[node]:
            if depth[nei] == -1:
                depth[nei] = depth[node] + 1
                bfs.append(nei)
    atdepth = [[] for _ in range(n)]
    for node in range(n):
        atdepth[depth[node]].append(node)
    return depth, atdepth


t = int(input())
for _ in range(t):
    n = int(input())
    coupl = [[] for _ in range(n)]
    for _ in range(n - 1):
        u,v = [int(x) - 1 for x in input().split()]
        coupl[u].append(v)
        coupl[v].append(u)
    leaves = [node for node in range(n) if len(coupl[node]) <= 1]

    y,d0 = query(list(range(n)))
    
    depth, atdepth = bfser(y, coupl)
    
    b = min(d0, max(depth))
    a = min(d0 + 1 >> 1, b)
    ax0 = None
    while a < b:
        c = a + b + 1 >> 1
        x0, d = query(atdepth[c])
        if d > d0:
            b = c - 1
        else:
            a = c
            ax0 = x0

    if ax0 is None:
        x0,_ = query(atdepth[a])
    else:
        x0 = ax0

    depth, atdepth = bfser(x0, coupl)
    
    x1,_ = query(atdepth[d0])

    ans(x0,x1)