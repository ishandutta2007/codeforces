def main():
    inp = readnumbers()
    ii = 0

    n = int(inp[ii])
    ii += 1
    x = int(inp[ii])
    ii += 1

    A = inp[ii:ii+n]
    ii += n
    
    DP = [[0]*3 for _ in range(n+1)]
    for i in range(n):
        # most beuty without using x in A[:i+1]
        DP[i][0] = max(0, DP[i-1][0] + A[i])
        # most beuty be currently use x in A[:i+1]
        DP[i][1] = max(0, DP[i-1][0] + x*A[i], DP[i-1][1] + x*A[i])
        # most buety by never using x after A[:i+1]
        DP[i][2] = max(0, DP[i][0], DP[i][1], DP[i-1][2] + A[i])

    print max(DP[i][2] for i in range(n))



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