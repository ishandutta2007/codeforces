import sys, os
 
class FenwickTree:
    def __init__(self, x):
        """transform list into BIT"""
        self.bit = x
        for i in range(len(x)):
            j = i | (i + 1)
            if j < len(x):
                x[j] += x[i]
 
    def update(self, idx, x):
        """updates bit[idx] += x"""
        while idx < len(self.bit):
            self.bit[idx] += x
            idx |= idx + 1
 
    def query(self, end):
        """calc sum(bit[:end])"""
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x
 
    def findkth(self, k):
        """Find largest idx such that sum(bit[:idx]) <= k"""
        idx = -1
        for d in reversed(range(len(self.bit).bit_length())):
            right_idx = idx + (1 << d)
            if right_idx < len(self.bit) and k >= self.bit[right_idx]:
                idx = right_idx
                k -= self.bit[idx]
        return idx + 1
 
ii = 0
_inp = b''
def getchar():
    global ii, _inp
    if ii >= len(_inp):
        _inp = os.read(0, 4000)
        ii = 0
    if not _inp:
        return b' '[0]
    ii += 1
    return _inp[ii - 1]
 
def input():
    c = getchar()
    if c == b'-'[0]:
        x = 0
        sign = 1
    else:
        x = c - b'0'[0]
        sign = 0
    c = getchar()
    while c >= b'0'[0]:
        x = 10 * x + c - b'0'[0]
        c = getchar()
    if c == b'\r'[0]:
        getchar()
    return -x if sign else x
        
n = input()
q = input()
A = [0]*n
for _ in range(n):
    A[input() - 1] += 1
 
fen = FenwickTree(A)
for _ in range(q):
    x = input()
    if x < 0:
        fen.update(fen.findkth(-x - 1), -1)
    else:
        fen.update(x - 1, 1)
i = 0
while i < n and not A[i]:
    i += 1
if i == n:
    os.write(1, b'0')
else:
    os.write(1, str(i + 1).encode('ascii'))