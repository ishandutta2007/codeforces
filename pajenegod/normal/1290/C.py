import sys
range = xrange
input = raw_input
 
n, k = [int(x) for x in input().split()]
A = [+(c == '0') for c in input()]
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

B = []
for _ in range(k):
    m = inp[ii]; ii += 1
    B.append([a - 1 for a in inp[ii: ii + m]]); ii += m

buckets = [[] for _ in range(n)]
for j in range(k):
    for a in B[j]:
        buckets[a].append(j)

#####################
parent = list(range(2 * k))
size = [1] * (2 * k)
state = [0] * (2 * k)
true = [1] * k + [0] * k
cost = 0


def find(a):
    acopy = a
    while a != parent[a]:
        a = parent[a]
    while acopy != a:
        parent[acopy], acopy = a, parent[acopy]
    return a

def calcer(a):
    a = find(a)
    b = find((a + k) % (2 * k))
    if state[a] == 0:
        return min(true[a], true[b])
    elif state[a] == 1:
        return true[b]
    else:
        return true[a]

def union(a, b):
    a, b = find(a), find(b)
    if a != b:
        if size[a] < size[b]:
            a, b = b, a

        parent[b] = a
        size[a] += size[b]
        state[a] |= state[b]
        true[a] += true[b]

def on(a):
    global cost
    a = find(a)
    if state[a] == 0:
        b = find((a + k) % (2 * k))
        cost -= calcer(a)
        state[a] = 1
        state[b] = 2 
        cost += calcer(a)

def same(a, b):
    global cost
    a = find(a)
    b = find(b)
    if a != b:
        cost -= calcer(a)
        cost -= calcer(b)
        union(a, b)
        union((a + k) % (2 * k), (b + k) % (2 * k))
        cost += calcer(a)

######

out = []
for i in range(n):
    bucket = buckets[i]
    if not bucket:
        pass
    elif len(bucket) == 1:
        j = bucket[0]
        if not A[i]:
            on(j)
        else:
            on(j + k)
    else:
        j1, j2 = bucket
        if not A[i]:
            same(j1, j2)
        else:
            same(j1, j2 + k)
    out.append(cost)
print '\n'.join(str(x) for x in out)