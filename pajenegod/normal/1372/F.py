import os
import sys
from __builtin__ import xrange as range
from cStringIO import StringIO
from future_builtins import ascii, filter, hex, map, oct, zip
from io import IOBase
 
import __pypy__
 
 
def main():
    rem = {}
    def query(l,r):
        if (l,r) not in rem:
            print '?', l + 1, r
            sys.stdout.flush()
            x,f = [int(x) for x in input().split()]
            rem[l,r] = x,f
        return rem[l,r]
 
    n = int(input())
 
    A = [-1]*n
    def solve(l,r):
        if l == r:
            return
        mid = l + r >> 1
 
        x0,f0 = query(l,r)
        if r - l == f0:
            for i in range(l,r):
                A[i] = x0
            return
        x1,f1 = query(l,mid)
        x2,f2 = query(mid,r)
 
        if x0 == x1 and f0 > f1:
            for i in range(mid - f1, mid - f1 + f0):
                A[i] = x0
            solve(l, mid - f1)
            solve(mid - f1 + f0, r)
        elif x0 == x2 and f0 > f2:
            for i in range(mid + f2 - f0, mid + f2):
                A[i] = x0
            solve(l, mid + f2 - f0)
            solve(mid + f2, r)
        else:
            solve(l,mid)
            solve(mid,r)
    solve(0,n)
    print '!', ' '.join(str(a) for a in A)
 
 
# region fastio
 
BUFSIZE = 8192
 
 
class FastI(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = StringIO()
        self.newlines = 0
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count("\n") + (not b)
            ptr = self._buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines -= 1
        return self._buffer.readline()
 
 
class FastO(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = __pypy__.builders.StringBuilder()
        self.write = lambda s: self._buffer.append(s)
 
    def flush(self):
        os.write(self._fd, self._buffer.build())
        self._buffer = __pypy__.builders.StringBuilder()
 
 
sys.stdin, sys.stdout = FastI(sys.stdin), FastO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
 
if __name__ == "__main__":
    main()