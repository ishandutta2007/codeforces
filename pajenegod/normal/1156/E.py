class segmenttree:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [0]*(2*m)
        self.data[m:m+n] = data
        for i in reversed(range(1,m)):
            self.data[i] = max(self.data[2*i],self.data[2*i+1])

    def maxi(self, l,r):
        l += self.m
        r += self.m
        m = 0
        while l<r:
            if l&1:
                m = max(m, self.data[l])
                l += 1
            if r&1:
                r -= 1
                m = max(m, self.data[r])
            l >>= 1
            r >>= 1
        return m

def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1

    P = inp[ii:]

    where = [0]*(n+1)
    for i in range(n):
        where[P[i]] = i

    ans = 0
    seg = segmenttree(P)
    Q = [(0,n)]
    for l,r in Q:
        if r-l<=2: continue

        maxi = seg.maxi(l,r)
        ind = where[maxi]

        int1 = (l,ind)
        int2 = (ind+1,r)
        Q.append(int1)
        Q.append(int2)

        if int1[1]-int1[0] > int2[1]-int2[0]:
            int1,int2 = int2,int1

        for i in range(*int1):
            goal = maxi - P[i]
            if 0<goal<=n and int2[0]<=where[goal]<int2[1]:
                ans += 1
    print ans


######## Python 2 and 3 footer by Pajenegod and c1729 

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
    from cStringIO import StringIO as BytesIO
else:
    from io import BytesIO
    __str__ = str
    str = lambda x=b'': x if type(x) is bytes else __str__(x).encode()

import os, sys
from io import IOBase

BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._buffer = BytesIO()
        self._file = file
        self._fd = file.fileno()
        self._writable = "x" in file.mode or "w" in file.mode
        if self._writable: self.write = self._buffer.write

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        b = self._buffer; b.seek((b.tell(), b.seek(0,2), b.write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return self._buffer.read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return self._buffer.readline()

    def flush(self):
        if self._writable:
            os.write(self._fd, self._buffer.getvalue())
            self._buffer.truncate(0), self._buffer.seek(0)

sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip(b'\r\n')

# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = b'\n'

# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero=0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.read()
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