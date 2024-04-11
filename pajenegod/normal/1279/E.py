import sys
range = xrange
input = raw_input

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]

        


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []

fact = [0]*52
fact[0] = 1
for i in range(1, 52):
    fact[i] = i * fact[i - 1]
fact.append(1)

counter = [0]*52
counter[0] = 1
for n in range(1, 52):
    for i in range(1, n + 1):
        counter[n] += fact[i - 2] * counter[n - i]


def solve(n, k):
    dsu = DisjointSetUnion(n + 1)
    ans = [0]*(n + 1)
    ans[1] = n
    dsu.union(1,n)
    taken = [0]*(n + 1)
    taken[n] = 1

    for i in range(2, n):
        for j in range(1, n):
            if not taken[j] and dsu.find(i) != dsu.find(j):
                if k >= fact[n - i - 1]:
                    k -= fact[n - i - 1]
                else:
                    taken[j] = 1
                    dsu.union(i, j)
                    ans[i] = j
                    break
    i = n
    for j in range(1,n):
        if not taken[j]:
            ans[i] = j
            break
    return ans[1:]

for _ in range(t):
    N = n = inp[ii]; ii += 1
    k = inp[ii] - 1; ii += 1

    if k >= counter[n]:
        out.append(-1)
    else:
        rem = []
        while n:
            for i in range(1, n + 1):
                if k >= fact[i - 2] * counter[n - i]:
                    k -= fact[i - 2] * counter[n - i]
                else:
                    x,k= divmod(k, counter[n - i])
                    rem.append((i, x))
                    n -= i
                    break
        
        ans = []
        cumsum = 0
        for count, k in rem:
            ans += (c + cumsum for c in solve(count, k))
            cumsum += count
        

        out.append(' '.join(str(x) for x in ans))
#        ans = [0]
#        for i in range(1, len(rem)):
#            rem[i] += rem[i - 1]
#
#        for r in rem[:-1]:
#            base = ans[-1]
#            ans.append(r)
#            for j in range(base + 1, r):
#                ans.append(j)
#        base = ans[-1]
#
#
#        if k > 1:
#            ans.append('va')
#        #numbs = [x for x in range(i)]
#        #while k:
#
#            
#        m = N - rem[-1]
#        for j in range(base + 1, base + 1 + m):
#            ans.append(j)
#
#        out.append((k, rem, ans))
print '\n'.join(str(x) for x in out)