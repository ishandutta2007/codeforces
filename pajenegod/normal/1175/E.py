big = 5*10**5 + 10
class minseg(object):
    def __init__(self, n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [big]*(m+m)
    def update(self,l,r,val):
        l += self.m
        r += self.m
        while l<r:
            if l&1:
                if self.data[l] > val:
                    self.data[l] = val
                l += 1
            if r&1:
                r -= 1
                if self.data[r] > val:
                    self.data[r] = val
            l>>=1
            r>>=1
    def get(self):
        for i in range(1, self.m):
            self.data[2*i] = min(self.data[2*i], self.data[i])
            self.data[2*i+1] = min(self.data[2*i+1], self.data[i])
        return self.data[self.m:self.m+self.n]

def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1
    m = inp[ii]
    ii += 1

    L = inp[ii:ii+2*n:2]
    R = inp[ii+1:ii+2*n:2]
    ii += 2*n

    X = inp[ii:ii+2*m:2]
    Y = inp[ii+1:ii+2*m:2]
    ii += 2*m

    seg = minseg(big)
    for i in range(n):
        seg.update(L[i],R[i]+1,L[i])
    
    P = seg.get()
    cover = [1 if p<big else 0 for p in P]
    P = [p if p<big else i for i,p in enumerate(P)]

    binary = [[P[0]]*20 for _ in range(big)]
    for i in range(1, big):
        binary[i][0] = P[i]
        for j in range(1,20):
            binary[i][j] = binary[binary[i][j-1]][j-1]

    for ind in range(m):
        l = X[ind]
        r = Y[ind]
        if l==r:
            if cover[l]:
                print 1
            else:
                print -1
            continue

        moves = 0
        k = 19
        while k>=0:
            while k>=0 and binary[r][k] <= l:
                k -= 1
            if k >= 0:
                r = binary[r][k]
                moves += 2**k
                k -= 1
        if P[r] <= l:
            print moves + 1
        else:
            print -1


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