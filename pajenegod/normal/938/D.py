from __future__ import division, print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import BytesIO, IOBase

# FastIO for PyPy2 and PyPy3 (works with interactive) by Pajenegod
class FastI(object):
    def __init__(self, fd=0, buffersize=2**14):
        self.stream = stream = BytesIO(); self.bufendl = 0
        def read2buffer():
            s = os.read(fd, buffersize + os.fstat(fd).st_size); pos = stream.tell()
            stream.seek(0,2); stream.write(s); stream.seek(pos); return s
        self.read2buffer = read2buffer
    # Read entire input
    def read(self):
        while self.read2buffer(): pass
        return self.stream.read() if self.stream.tell() else self.stream.getvalue()
    def readline(self):
        while self.bufendl == 0: s = self.read2buffer(); self.bufendl += s.count(b'\n') + (not s)
        self.bufendl -= 1; return self.stream.readline()
    def input(self): return self.readline().rstrip(b'\r\n')
    
    # Read all remaining integers, type is given by optional argument
    def readnumbers(self, zero=0):
        conv = ord if py2 else lambda x:x
        A = []; numb = zero; sign = 1; c = b'-'[0]
        for c in self.read():
            if c >= b'0'[0]: numb = 10 * numb + conv(c) - 48
            elif c == b'-'[0]: sign = -1
            elif c != b'\r'[0]: A.append(sign*numb); numb = zero; sign = 1
        if c >= b'0'[0]: A.append(sign*numb)
        return A

class FastO(IOBase):
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
        self.write = stream.write if py2 else lambda s: stream.write(s.encode())

sys.stdin, sys.stdout = FastI(), FastO()
input = sys.stdin.readline

big = 3E12
class segheap:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m

        self.data = [big]*(2*m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(1, m)):
            self.data[i] = min(self.data[2*i],self.data[2*i^1])

    def mini(self):
        val = self.data[1]
        i = 1
        while i<self.m:
            i <<= 1
            if self.data[i]!=val:
                i ^= 1
        return self.setter(i-self.m,big) or i-self.m

    def setter(self,ind,val):
        ind += self.m
        while ind:
            self.data[ind] = val
            val = min(val, self.data[ind^1])
            ind //= 2

inp = sys.stdin.readnumbers(0.0)
ind = 0

n = int(inp[ind])
ind += 1
m = int(inp[ind])
ind += 1

coupl = [[] for _ in range(n)]
cost = [[] for _ in range(n)]
for _ in range(m):
    v = int(inp[ind+0]) - 1
    u = int(inp[ind+1]) - 1
    w = inp[ind+2]
    ind += 3
    coupl[v].append(u)
    coupl[u].append(v)
    cost[u].append(w)
    cost[v].append(w)

best = inp[ind:]
ind += n

Q = segheap(best)

while Q.data[1]!=big:
    c = Q.data[1]
    node = Q.mini()
    if best[node]!=c:
        continue
    for j in range(len(coupl[node])):
        nei = coupl[node][j]
        C = c + 2*cost[node][j]
        if C<best[nei]:
            best[nei] = C
            Q.setter(nei,C)

for x in best:
    sys.stdout.write(str(int(x)))
    sys.stdout.write(' ')