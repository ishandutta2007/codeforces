from collections import defaultdict
import sys
input = raw_input
range = xrange
 
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
        self.fenwick = FenwickTree([])
        self.size = 0
        # Cache last prev_count(i) call
        self.cached_i = 0
        self.cached_size = 0
        # Cache _lower_bound(x)
        self.cached_x = None
        self.cached_index = (-1,0)
 
    def lower_bound(self, x):
        i,j = self._lower_bound(x)
        return self.prev_count(i) + j
    
    def upper_bound(self, x):
        i = upper_bound(self.macro, x)
        i -= i and self.micro_size[i - 1] and x < self.micros[i - 1][-1]
        return self.prev_count(i) + upper_bound(self.micros[i], x)
 
    def insert(self, x):
        i,j = self._lower_bound(x)
        self.micros[i].insert(j, x)
        self.size += 1
        self.micro_size[i] += 1
        self.fenwick.update(i, 1)
        self.cached_size += i < self.cached_i
        if len(self.micros[i]) >= block_size:
            self.cached_index = (-1, 0)
            self.cached_i += i < self.cached_i
            
            self.micros[i : i + 1] = self.micros[i][:block_size >> 1], self.micros[i][block_size >> 1:]
            self.micro_size[i : i + 1] = block_size >> 1, block_size >> 1
            self.fenwick.size = 0
            self.macro [i : i + 1] = self.micros[i][0], self.micros[i + 1][0]
            if len(self.micros) == len(self.macro):
                self.macro.pop()
    
    def remove(self, x):
        i,j = self._lower_bound(x)
        self._delete(i,j)
    
    def __delitem__(self, k):
        i,j = self.find_kth(k)
        self._delete(i,j)

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
        if k < self.cached_size:
            self.cached_i -= 1
            self.cached_size -= self.micro_size[self.cached_i]
        elif self.cached_size + self.micro_size[self.cached_i] <= k:
            self.cached_size += self.micro_size[self.cached_i]
            self.cached_i += 1

        if not 0 <= k - self.cached_size < self.micro_size[self.cached_i]:
            if self.fenwick.size == 0:
                self.fenwick.build(self.micro_size)
            self.cached_i,j = self.fenwick.find_kth(k)
            
            if j < self.micro_size[self.cached_i]:
                self.cached_size = k - j
            else:
                self.cached_i -= 1
                self.cached_size = k - self.micro_size[i - 1] - 1
        return self.cached_i, k - self.cached_size
 
    def prev_count(self, i):
        if i == self.cached_i:
            return self.cached_size
        if i < 10:
            self.cached_size = 0
            for j in range(i):
                self.cached_size += self.micro_size[j]
        elif len(self.micro_size) - i < 10:
            self.cached_size = self.size
            for j in range(i, len(self.micros)):
                self.cached_size -= self.micro_size[j]
        elif -10 < self.cached_i - i < 10:
            for j in range(i, self.cached_i):
                self.cached_size -= self.micro_size[j]
            for j in range(self.cached_i, i):
                self.cached_size += self.micro_size[j]
        else:
            if self.fenwick.size == 0:
                self.fenwick.build(self.micro_size)
            self.cached_size = self.fenwick(i)
        self.cached_i = i
        return self.cached_size
 
    def _lower_bound(self, x):
        if self.cached_index[0] >= 0 and self.cached_x == x:
            return self.cached_index
        i = lower_bound(self.macro, x)
        i -= i and self.micro_size[i - 1] and x <= self.micros[i - 1][-1]
        j = lower_bound(self.micros[i], x)
        self.cached_x = x
        self.cached_index = (i,j)
        return i, j
 
    def _delete(self, i, j):
        del self.micros[i][j]
        self.size -= 1
        self.micro_size[i] -= 1
        self.fenwick.update(i, -1)
        if i == self.cached_index[0] and j < self.cached_index[1]:
            self.cached_index = (i, self.cached_index[1] - 1)
        self.cached_size -= i < self.cached_i
        if 1 < i + 1 < len(self.micro_size) and self.micro_size[i - 1] + self.micro_size[i] + self.micro_size[i + 1] < block_size:
            self.cached_index = (-1, 0)
            if self.cached_i == i:
                self.cached_size -= self.micro_size[i - 1]
            elif self.cached_i == i + 1:
                self.cached_size -= self.micro_size[i - 1] + self.micro_size[i]
            self.cached_i -= (i <= self.cached_i) + (i < self.cached_i)
            
            self.micros[i - 1] += self.micros[i]
            self.micros[i - 1] += self.micros[i + 1]
            self.micro_size[i - 1] += self.micro_size[i] + self.micro_size[i + 1]
            del self.macro[i - 1: i + 1], self.micros[i: i + 2], self.micro_size[i: i + 2]
            self.fenwick.size = 0
 
inp = sys.stdin.read().split(); ii = 0
n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1
S = inp[ii]; ii += 1
 
B = blocksorter()
Bc = defaultdict(lambda : blocksorter())
for i in range(n):
    B.insert(i)
    Bc[S[i]].insert(i)
 
for _ in range(m):
    l = int(inp[ii]) - 1; ii += 1
    r = int(inp[ii]) - 1; ii += 1
    c = inp[ii]; ii += 1
 
    Bcc = Bc[c]
 
    L = B[l]
    R = B[r]

    k = Bcc.lower_bound(L)
    while k < len(Bcc) and Bcc[k] <= R:
        B.remove(Bcc[k])
        del Bcc[k]
    
print ''.join(S[i] for b in B.micros for i in b)