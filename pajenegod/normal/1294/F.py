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

root = 0
bfs = [root]
#P = [-1]*n

for node in bfs:
    for nei in coupl[node]:
        tmp = coupl[nei]
        i = 0
        while tmp[i] != node:
            i += 1
        tmp.pop(i)
        bfs.append(nei)
#        P[nei] = node

depth = [0]*n
depthid = list(range(n))
for node in reversed(bfs):
    if coupl[node]:
        for nei in coupl[node]:
            if depth[node] < depth[nei] + 1:
                depth[node] = depth[nei] + 1
                depthid[node] = depthid[nei]

best = 0
abest = 0
bbest = 0
cbest = 0


upheight = [0]*n
upheightid = list(range(n))
for node in bfs:
    tmp = coupl[node]
    maxi = max(tmp, key = depth.__getitem__) if tmp else -1
    maxi2 = max((nei for nei in tmp if nei != maxi), key = depth.__getitem__) if len(tmp) >= 2 else -1
    maxi3 = max((nei for nei in tmp if nei != maxi and nei != maxi2), key = depth.__getitem__) if len(tmp) >= 3 else -1

    for nei in tmp:
        val = upheight[node]
        who = upheightid[node]
        if nei != maxi and maxi >= 0 and depth[maxi] + 1 > val:
            val = depth[maxi] + 1
            who = depthid[maxi]
        if nei != maxi2 and maxi2 >= 0 and depth[maxi2] + 1 > val:
            val = depth[maxi2] + 1
            who = depthid[maxi2]
        upheight[nei] = val + 1
        upheightid[nei] = who

    a = 0
    b = 0
    c = 0
    if not tmp:
        val = upheight[node]
        a = upheightid[node]
        b = node
    elif len(tmp) == 1:
        val = upheight[node] + depth[maxi] + 1
        a = upheightid[node]
        b = depthid[maxi]
    elif len(tmp) == 2:
        val = upheight[node] + depth[maxi] + depth[maxi2] + 2
        a = upheightid[node]
        b = depthid[maxi]
        c = depthid[maxi2]
    else:
        val1 = upheight[node] + depth[maxi] + depth[maxi2] + 2
        val2 = depth[maxi] + depth[maxi2] + depth[maxi3] + 3
        if val1 > val2:
            val = val1
            a = upheightid[node]
            b = depthid[maxi]
            c = depthid[maxi2]
        else:
            val = val2
            a = depthid[maxi]
            b = depthid[maxi2]
            c = depthid[maxi3]
            

    if val > best:
        best = val
        besta = a
        bestb = b
        bestc = c
print best

a,b,c = besta, bestb, bestc
if a == b:
    a = 0
if a == c:
    a = 0
if b == c:
    b = 0
while a == b or a == c:
    a += 1
while b == a or b == c:
    b += 1
while c == a or c == b:
    c += 1

print a + 1, b + 1, c + 1