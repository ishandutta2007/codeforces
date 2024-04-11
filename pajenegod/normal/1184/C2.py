def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1
    r = inp[ii]
    ii += 1

    A = []
    B = []
    for i in range(n):
        x = inp[ii]
        ii += 1
        y = inp[ii]
        ii += 1
        A.append(x+y)
        B.append(x-y)


    xcoords = []
    for a in A:
        xcoords.append(a + r)
        xcoords.append(a - r)
    
    ycoords = []
    for b in B:
        ycoords.append(b + r)
        ycoords.append(b - r)

    xmapper = {}
    for i,x in enumerate(sorted(set(xcoords))):
        xmapper[x] = i

    ymapper = {}
    for i,y in enumerate(sorted(set(ycoords))):
        ymapper[y] = i


    starts = [[] for _ in range(len(xmapper))]
    ends = [[] for _ in range(len(xmapper))]

    for a,b in zip(A,B):
        starts[xmapper[a-r]].append(b)
        ends[xmapper[a+r]].append(b)

    maxi = 0

    seg = LazySegmentTree(len(ymapper))
    for i in range(len(xmapper)):
        for b in starts[i]:
            bstart = ymapper[b-r]
            bend = ymapper[b+r] + 1
            seg.add(bstart, bend, 1)
        
        maxi = max(maxi, seg.data[1])
        
        for b in ends[i]:
            bstart = ymapper[b-r]
            bend = ymapper[b+r] + 1
            seg.add(bstart, bend, -1)

    print maxi


class LazySegmentTree:
    def __init__(self, n, padding = 0, func=max):
        """initialize the lazy segment tree with data"""
        self._func = func
        self._len = n
        self._size = _size = 1 << (self._len - 1).bit_length()
        
        self.data = [padding] * (2 * _size)
        self._lazy = [0] * (2 * _size)
 
    def _push(self, idx):
        """push query on idx to its children"""
        # Let the children know of the queries
        # TODO
        q = self._lazy[idx]
        self._lazy[idx] = 0
        
        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q
 
        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q
 
    def _build(self, idx):
        """make the changes to idx be known to its ancestors"""
        idx >>= 1
        while idx:
            # TODO
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1
 
    def _update(self, idx):
        """updates the node idx to know of all queries applied to it via its ancestors"""
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)
 
    def add(self, start, stop, value):
        """lazily add value to [start, stop)"""
        start = start_copy = start + self._size
        stop = stop_copy = stop + self._size
 
        # Apply all the lazily stored queries
        #self._update(start); self._update(stop - 1)
        
        while start < stop:
            if start & 1:
                self.data[start] += value
                self._lazy[start] += value
                start += 1
            if stop & 1:
                stop -= 1
                self.data[stop] += value
                self._lazy[stop] += value
            
            start >>= 1; stop >>= 1
        
        self._build(start_copy); self._build(stop_copy - 1)
 
    def query(self, start, stop, res = 0):
        """func of data[start, stop)"""
        start += self._size; stop += self._size
 
        # Apply all the lazily stored queries
        self._update(start); self._update(stop - 1)
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(self.data[stop], res)
            start >>= 1; stop >>= 1
        return res
 
    def node_size(self, idx):
        return 1 << self._size.bit_length() - idx.bit_length()


######## Python 2 and 3 footer by Pajenegod and c1729

# Note because cf runs old PyPy3 version which doesn't have the sped up
# unicode strings, PyPy3 strings will many times be slower than pypy2.
# There is a way to get around this by using binary strings in PyPy3
# but its syntax is different which makes it kind of a mess to use.

# So on cf, use PyPy2 for best string performance.

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = '\n'

# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero = 0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.buffer.read()
    try:
        while True:
            if s[i] >= b'0' [0]:
                numb = 10 * numb + conv(s[i]) - 48
            elif s[i] == b'-' [0]: sign = -1
            elif s[i] != b'\r' [0]:
                A.append(sign*numb)
                numb = zero; sign = 1
            i += 1
    except:pass
    if s and s[-1] >= b'0' [0]:
        A.append(sign*numb)
    return A

if __name__== "__main__":
  main()