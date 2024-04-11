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

################## CODE

n,h = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

a = 0
b = n
while a<b:
    c = (a+b+1)//2
    B = sorted(A[:c],reverse=True)
    space = sum(B[::2])
    if space<=h:
        a = c
    else:
        b = c-1
print(a)