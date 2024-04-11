import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, data):
        n = len(data)
        self.m = 1
        while self.m < n: self.m *= 2

        self.data = [0] * (2 * self.m)
        self.data[self.m: self.m + n] = data

        for i in reversed(range(1, self.m)):
            self.data[i] = self.data[2 * i] + self.data[2 * i + 1]

    def __setitem__(self, i, x):
        i += self.m
        self.data[i] = x
        i >>= 1
        while i:
            self.data[i] = self.data[2 * i] + self.data[2 * i + 1]
            i >>= 1

    def finder(self, k):
        if k == 0:
            return -1
        assert self.data[1] >= k
        i = 1
        while i < self.m:
            i *= 2
            if self.data[i] < k:
                k -= self.data[i]
                i += 1
        return i - self.m
    
    def getter(self, l, r):
        l += self.m
        r += self.m
        s = 0
        while l < r:
            if l & 1:
                s += self.data[l]
                l += 1
            if r & 1:
                r -= 1
                s += self.data[r]
            l >>= 1
            r >>= 1
        return s

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

N = inp[ii]; ii += 1
M = inp[ii]; ii += 1
k = inp[ii]; ii += 1

T = inp[ii + 0: ii + 3 * N: 3]
A = inp[ii + 1: ii + 3 * N: 3]
B = inp[ii + 2: ii + 3 * N: 3]

order = sorted(range(N), key = T.__getitem__)
T = [T[i] for i in order]
A = [A[i] for i in order]
B = [B[i] for i in order]

TA = []
TB = []
TAB = []
for i in range(N):
    if A[i] and B[i]:
        TAB.append(i)
    elif A[i]:
        TA.append(i)
    elif B[i]:
        TB.append(i)

n = len(TA)
m = len(TB)
nm = len(TAB)

mark = [1] * N
times = list(T)

upper = min(k, nm)
picked = k - upper
if picked > n or picked > m:
    print -1
    sys.exit()

tsum = 0

for j in range(picked):
    i = TA[j]
    tsum += T[i]
    mark[i] = 0
    times[i] = 0
    
    i = TB[j]
    tsum += T[i]
    mark[i] = 0
    times[i] = 0

for j in range(upper):
    i = TAB[j]
    tsum += T[i]
    mark[i] = 0
    times[i] = 0

marker = segtree(mark)
timer = segtree(times)

time = inf = 10**9 * 2 + 100
optx = -1

for x in reversed(range(upper + 1)):
    books = x + 2 * (k - x)
    if books <= M:
        cand = tsum + timer.getter(0, marker.finder(M - books) + 1)
        if cand < time:
            time = cand
            optx = x
    if x:
        i = TAB[x - 1]
        tsum -= T[i]
        marker[i] = mark[i] = 1
        timer[i] = times[i] = T[i]
    
    j = k - x
    if j >= n or j >= m:
        break
    
    i = TA[j]
    tsum += T[i]
    marker[i] = mark[i] = 0
    timer[i] = times[i] = 0
    
    i = TB[j]
    tsum += T[i]
    marker[i] = mark[i] = 0
    timer[i] = times[i] = 0

if time == inf:
    print -1
else:
    print time
    ab = optx
    a = b = k - optx
    rest = M - ab - a - b
    picked = []
    for i in range(N):
        if A[i] and B[i] and ab:
            ab -= 1
            picked.append(i)
        elif not B[i] and A[i] and a:
            a -= 1
            picked.append(i)
        elif not A[i] and B[i] and b:
            b -= 1
            picked.append(i)
        elif rest:
            picked.append(i)
            rest -= 1
    print ' '.join(str(order[x] + 1) for x in picked)