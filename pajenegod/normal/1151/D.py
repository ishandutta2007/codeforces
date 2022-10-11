def main():
    n = int(input())
    a = [list(map(int, input().split())) for i in range(n)]
    a.sort(key=lambda x: x[1] - x[0])
    print sum(a[i][0] * i + a[i][1] * (n - 1 - i) for i in range(n))


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

# cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = b'\n'

if __name__== "__main__":
  main()