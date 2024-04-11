from __future__ import print_function
py2 = round(0.5)

if py2:
    from cStringIO import StringIO as BytesIO
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
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

sys.stdin = FastIO(sys.stdin); sys.stdout = FastIO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip()

class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = b'\n'

#################
x1,x2,x3,x4 = sorted([int(x) for x in input().split()])

c = x4 - x1
a = x4 - x2
b = x4 - x3

cout << a << " " << b << " " << c << '\n'