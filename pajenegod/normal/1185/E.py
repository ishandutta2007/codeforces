from __future__ import print_function
from collections import defaultdict as di

def solve():
    n,m = map(int,input().split())
    B = [input() for _ in range(n)]

    pos = di(list)
    for i in range(n):
        b = B[i]
        for j in range(m):
            pos[b[j]].append((i,j))
    if '.' in pos:
        del pos['.']

    C = [list('.'*m) for _ in range(n)]
    moves = []

    if pos:
        mxx = max(pos)
        for i in range(97,ord(mxx)+1):
            c = chr(i)
            if c not in pos:
                pos[c] = pos[mxx]
            P = pos[c]
            if all(p[0] == P[0][0] for p in P):
                mn = min(p[1] for p in P)
                mx = max(p[1] for p in P)
                i = P[0][0]
                for j in range(mn,mx+1):
                    C[i][j] = c
                moves.append((i+1,mn+1,i+1,mx+1))
            elif all(p[1] == P[0][1] for p in P):
                mn = min(p[0] for p in P)
                mx = max(p[0] for p in P)
                j = P[0][1]
                for i in range(mn,mx+1):
                    C[i][j] = c
                moves.append((mn+1,j+1,mx+1,j+1))
    
    if [''.join(s) for s in C] == B:
        print('YES')
        print(len(moves))
        for m in moves:
            print(*m)
    else:
        print('NO')

def main():

    for _ in range(t):
        solve()

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
class FastIO(object):
    newlines = 0

    def __init__(self, file):
        self.stream = BytesIO()
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = self.stream.write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.stream.seek((self.stream.tell(), self.stream.seek(0,2), self.stream.write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return self.stream.read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return self.stream.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.stream.getvalue())
            self.stream.truncate(0), self.stream.seek(0)

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
input = lambda: sys.stdin.readline().rstrip()

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

t = int(input())
input = lambda: sys.stdin.buffer.stream.readline().rstrip()
if __name__== "__main__":
  main()