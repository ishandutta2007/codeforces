import sys
range = xrange
input = raw_input

try:
    def find_SCC(coupl):
        SCC, S, P = [], [], []
        depth = [0] * len(coupl)
     
        stack = list(range(len(coupl)))
        while stack:
            node = stack.pop()
            if node < 0:
                d = depth[~node] - 1
                if P[-1] > d:
                    SCC.append(S[d:])
                    del S[d:], P[-1]
                    for node in SCC[-1]:
                        depth[node] = -1
            elif depth[node] > 0:
                while P[-1] > depth[node]:
                    P.pop()
            elif depth[node] == 0:
                S.append(node)
                P.append(len(S))
                depth[node] = len(S)
                stack.append(~node)
                stack += coupl[node]
        return SCC[::-1]


    class DisjointSetUnion:
        def __init__(self, n):
            parent = self.parent = list(range(n))
            size = self.size = [1] * n

            def __getitem__(a):
                acopy = a
                while a != parent[a]:
                    a = parent[a]
                while acopy != a:
                    parent[acopy], acopy = a, parent[acopy]
                return a
            self.__getitem__ = __getitem__

            def join(a, b):
                a, b = __getitem__(a), __getitem__(b)
                if a != b:
                    if size[a] < size[b]:
                        a, b = b, a

                    parent[b] = a
                    size[a] += size[b]
            self.join = join

    inp = [int(x) for x in sys.stdin.read().split()]; ii = 0


    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1

    P = inp[ii: ii + n]; ii += n
    P = [p - 1 for p in P]

    X = inp[ii + 0: ii + 2 * k: 2]
    Y = inp[ii + 1: ii + 2 * k: 2]
    X = [x - 1 for x in X]
    Y = [y - 1 for y in Y]

    ii += 2 * k

    dsu = DisjointSetUnion(n)
    for i in range(k):
        x = X[i]
        y = Y[i]
        dsu.join(x,y)

    buckets = [[] for _ in range(n)]
    for i in range(n):
        buckets[dsu[i]].append(i)

    after = [[] for _ in range(n)]
    counter = [0] * n
    for i in range(n):
        p = P[i]
        if p >= 0:
            i = dsu[i]
            p = dsu[p]
            if i != p:
                after[p].append(i)
                counter[i] += 1

    root = 0
    while P[root] >= 0:
        root += 1

    if counter[dsu[root]]:
        sys.exit()

    bfs = [dsu[root]]
    for node in bfs:
        for nei in after[node]:
            counter[nei] -= 1
            if counter[nei] == 0:
                bfs.append(nei)

    coupl = [[] for _ in range(n)]
    for i in range(k):
        x = X[i]
        y = Y[i]
        if dsu[x] == dsu[y]:
            coupl[x].append(y)

    SCC = find_SCC(coupl)
    if len(SCC) != n:
        sys.exit()

    order = [-1] * n
    for i in range(n):
        order[SCC[i][0]] = i

    A = []
    for node in bfs:
        strip = buckets[node]
        A += sorted(strip, key = order.__getitem__)

    place = [-1] * n
    for i in range(n):
        place[A[i]] = i

    for i in range(k):
        x = X[i]
        y = Y[i]
        
        if place[x] + 1 != place[y]:
            sys.exit()

    for i in range(n):
        p = P[i]
        if p >= 0 and place[p] >= place[i]:
            sys.exit()

    print ' '.join(str(x + 1) for x in A)
except:
    print 0
    sys.exit()