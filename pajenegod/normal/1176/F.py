def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1

    blocks = []
    for _ in range(n):
        k = inp[ii]
        ii += 1

        cost1 = []
        cost2 = []
        cost3 = []

        for _ in range(k):
            cost = inp[ii]
            ii += 1
            damage = inp[ii]
            ii += 1

            if cost == 1:
                cost1.append(damage)
            elif cost == 2:
                cost2.append(damage)
            else:
                cost3.append(damage)
        cost1.sort(reverse=True)
        cost2 = max(cost2 or [None])
        cost3 = max(cost3 or [None])

        cost1 = cost1[:3]
        blocks.append((cost1,cost2,cost3))
    
    best = [[0]*10 for _ in range(n+1)]
    for i in reversed(range(n)):
        cost1,cost2,cost3 = blocks[i]
            
        for j in range(10):
            ans = best[i+1][j]
            val1 = best[i+1][(j+1)%10]
            val2 = best[i+1][(j+2)%10]
            val3 = best[i+1][(j+3)%10]
            
            if cost1:
                val = val1 + (2*cost1[0] if j+1==10 else cost1[0])
                if val > ans:
                    ans = val
            if cost2:
                val = val1 + (2*cost2 if j+1==10 else cost2)
                if val > ans:
                    ans = val
            if cost3:
                val = val1 + (2*cost3 if j+1==10 else cost3)
                if val > ans:
                    ans = val
            if cost1 and cost2:
                a,b = cost1[0],cost2
                if a<b:
                    a,b = b,a 
                val = val2 + b + (2*a if j+2>=10 else a)
                if val > ans:
                    ans = val
            if len(cost1)>1:
                val = val2 + cost1[1] + (2*cost1[0] if j+2>=10 else cost1[0])
                if val > ans:
                    ans = val
            
            if len(cost1)>2:
                val = val3 + cost1[1] + cost1[2] + (2*cost1[0] if j+3>=10 else cost1[0])
                if val > ans:
                    ans = val
            best[i][j] = ans
     
    print best[0][0]
    




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