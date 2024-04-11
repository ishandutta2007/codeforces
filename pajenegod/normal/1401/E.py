import sys
range =  xrange
input = raw_input

### Sorted list

def lower_bound(A, x):
    a = 0
    b = len(A)
    while a < b:
        c = (a + b) >> 1
        if A[c] < x:
            a = c + 1
        else:
            b = c
    return a
 
def upper_bound(A, x):
    a = 0
    b = len(A)
    while a < b:
        c = (a + b) >> 1
        if A[c] <= x:
            a = c + 1
        else:
            b = c
    return a
 
 
class FenwickTree:
    def __init__(self, x):
        self.bit = []
        self.build(x)
    
    def build(self, x):
        """transform x into a BIT""" 
        self.bit[:] = x
        bit = self.bit
        size = self.size = len(x)
        for i in range(size):
            j = i | (i + 1)
            if j < size:
                bit[j] += bit[i]
 
    def update(self, idx, x):
        """updates bit[idx] += x"""
        while idx < self.size:
            self.bit[idx] += x
            idx |= idx + 1
 
    def __call__(self, end):
        """calc sum(bit[:end])"""
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x
 
    def find_kth(self, k):
        """Find largest idx such that sum(bit[:idx]) <= k"""
        idx = -1
        for d in reversed(range(self.size.bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < self.size and self.bit[right_idx] <= k:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1, k

block_size = 700
class blocksorter:
    def __init__(self):
        self.macro = []
        self.micros = [[]]
        self.micro_size = [0]
        self.fenwick = FenwickTree([0])
        self.size = 0
 
    def lower_bound(self, x):
        i = lower_bound(self.macro, x)
        i -= i and self.micro_size[i - 1] and x <= self.micros[i - 1][-1]
        return self.fenwick(i) + lower_bound(self.micros[i], x)
    
    def upper_bound(self, x):
        i = upper_bound(self.macro, x)
        i -= i and self.micro_size[i - 1] and x < self.micros[i - 1][-1]
        return self.fenwick(i) + upper_bound(self.micros[i], x)
 
    def insert(self, x):
        i,j = self._lower_bound(x)
        self.micros[i].insert(j, x)
        self.size += 1
        self.micro_size[i] += 1
        self.fenwick.update(i, 1)
        if len(self.micros[i]) >= block_size:
            self.micros[i : i + 1] = self.micros[i][:block_size >> 1], self.micros[i][block_size >> 1:]
            self.micro_size[i : i + 1] = block_size >> 1, block_size >> 1
            self.fenwick.build(self.micro_size)
            self.macro [i : i + 1] = self.micros[i][0], self.micros[i + 1][0]
            if len(self.micros) == len(self.macro):
                self.macro.pop()
    
    def __delitem__(self, k):
        i,j = self.find_kth(k)
        del self.micros[i][j]
        self.size -= 1
        self.micro_size[i] -= 1
        self.fenwick.update(i, -1)
        if 1 < i + 1 < len(self.micro_size) and self.micro_size[i - 1] + self.micro_size[i] + self.micro_size[i + 1] < block_size:
            self.micros[i - 1] += self.micros[i]
            self.micros[i - 1] += self.micros[i + 1]
            self.micro_size[i - 1] += self.micro_size[i] + self.micro_size[i + 1]
            del self.macro[i - 1: i + 1], self.micros[i: i + 2], self.micro_size[i: i + 2]
            self.fenwick.build(self.micro_size)
    
    def __getitem__(self, k):
        i,j = self.find_kth(k)
        return self.micros[i][j]
    
    def __len__(self):
        return self.size
 
    def __contains__(self, x):
        i,j = self._lower_bound(x)
        return j < len(self.micros[i]) and self.micros[i][j] == x
    
    # Internal functions
    def find_kth(self, k):
        if k < 0:
            k += self.size
        i,j = self.fenwick.find_kth(k)
        return (i,j) if j < len(self.micros[i]) else (i - 1, -1)
    
    def _lower_bound(self, x):
        i = lower_bound(self.macro, x)
        i -= i and self.micro_size[i - 1] and x <= self.micros[i - 1][-1]
        return i, lower_bound(self.micros[i], x)

###


big = 10**6

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

Y  = inp[ii + 0: ii + 3 * n: 3]
LX = inp[ii + 1: ii + 3 * n: 3]
RX = inp[ii + 2: ii + 3 * n: 3]
ii += 3 * n

Y.append(0)
LX.append(0)
RX.append(big)

Y.append(big)
LX.append(0)
RX.append(big)

n += 2

X  = inp[ii + 0: ii + 3 * m: 3]
LY = inp[ii + 1: ii + 3 * m: 3]
RY = inp[ii + 2: ii + 3 * m: 3]
ii += 3 * m

X.append(0)
LY.append(0)
RY.append(big)

X.append(big)
LY.append(0)
RY.append(big)

m += 2

start_buckets = [[] for _ in range(big + 1)]
remove_buckets = [[] for _ in range(big + 1)]
for i in range(n):
    start_buckets[LX[i]].append(i)
    remove_buckets[RX[i]].append(i)

buckets = [[] for _ in range(big + 1)]
for i in range(m):
    buckets[X[i]].append(i)

count = 0

sortedlist = blocksorter()
for x in range(big + 1):
    for i in start_buckets[x]:
        #print 'adding horizontal line', i
        sortedlist.insert(Y[i])
    
    for i in buckets[x]:
        #print 'Working with vertical line', i
        a = sortedlist.lower_bound(LY[i])
        b = sortedlist.upper_bound(RY[i])
        
        count += b - a
    
    for i in remove_buckets[x]:
        #print 'removing horizontal line', i
        del sortedlist[sortedlist.lower_bound(Y[i])]

print count - m - n + 1