from __future__ import division, print_function

def main():
    n, m = map(int, input().split())
    s = [[1 if c == '*' else 0 for c in input()] for _ in range(n)]
    strans = list(zip(*s))
    cnt = 0
    for i in range(n):
        si = s[i]
        for j in range(m):
            if si[j]:
                cnt += 1

    for i in range(1, n - 1):
        si = s[i]
        for j in range(1, m - 1):
            if si[j]:
                stransj = strans[j]
                k = j + 1
                while k < m and si[k]:
                    k += 1
                a = k - (j + 1)

                k = j - 1
                while k >= 0 and si[k]:
                    k -= 1
                b = j - 1 - k

                k = i - 1
                while k >= 0 and stransj[k]:
                    k -= 1
                c = i - 1 - k
                
                k = i + 1
                while k < n and stransj[k]:
                    k += 1
                d = k - (i + 1)

                if a != 0 and b != 0 and c != 0 and d != 0 and a + b + c + d + 1 == cnt:
                    print("YES")
                    return
                    
    print("NO")


# PyPy 2 Fast IO
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

# Importing Modules
import math
import collections

from collections import Counter
from math import fabs

if __name__ == "__main__":
    main()