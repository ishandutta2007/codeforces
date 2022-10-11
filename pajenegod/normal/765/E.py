import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1

    coupl[u].append(v)
    coupl[v].append(u)

def root(x):
    P = [-1]*n
    P[x] = x
    bfs = [x]
    for node in bfs:
        for nei in coupl[node]:
            if P[nei] == -1:
                P[nei] = node
                bfs.append(nei)

    children = [[] for _ in range(n)]
    for j in reversed(range(1,n)):
        node = bfs[j]
        my_children = set(children[node])
        if len(my_children) > 1:
            return False, node
        else:
            if my_children:
                children[P[node]] += (i + 1 for i in my_children)
            else:
                children[P[node]].append(1)
    orig = set(children[x])
    if len(orig)>2:
        return False, x
    else:
        return True, sum(orig) + 1

suc, ans = root(0)
if not suc:
    suc, ans = root(ans)
    
finalsum = ans
if not suc:
    print -1
else:
    while finalsum & 1 and finalsum > 1:
        finalsum = (finalsum + 1)//2
    print finalsum - 1