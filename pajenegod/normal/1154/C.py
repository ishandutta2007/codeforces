py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
    from cStringIO import StringIO as BytesIO
else:
    from io import BytesIO
    from builtins import str as __str__
    str = lambda x=b'': x if type(x) is bytes else __str__(x).encode()

import os, sys
from io import IOBase

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
        while self.bufendl == 0: s = self.read2buffer(); self.bufendl += s.count(b"\n") + (not s)
        self.bufendl -= 1; return self.stream.readline()
    
    def input(self): return self.readline().rstrip(b'\r\n')
    
    # Read all remaining integers, type is given by optional argument, this is fast
    def readnumbers(self, zero=0):
        conv = ord if py2 else lambda x:x
        A = []; numb = zero; sign = 1; i = 0; s = self.read()
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

class FastO(IOBase):
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
        self.write = stream.write if py2 else lambda s: stream.write(s.encode())

sys.stdin, sys.stdout = FastI(), FastO()
input = sys.stdin.input

import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
    def tie(self, val):pass
    def flush(self):sys.stdout.flush()
cout = ostream()
endl = b'\n'

class istream:
    inp = None
    def __rlshift__(a,b):
        if type(b)==tuple or type(b)==list:
            return type(b)(type(c)(a.get()) for c in b)
        return type(b)(a.get())
    def get(a):
        while not a.inp:
            a.inp = sys.stdin.readline().split(); a.inp.reverse()
        return a.inp.pop()
cin = istream()


## CODE


A = [int(x) for x in input().split()]

foods = [0,1,2,0,2,1,0]

week = [0]*3
for f in foods:
    week[f] += 1

weeks_l = 0
weeks_r = 10**12
while weeks_l<weeks_r:
    m = (weeks_l + weeks_r + 1)//2
    B = A[:]
    for i in range(3):
        B[i] -= week[i]*m
    if all(b>=0 for b in B):
        weeks_l = m
    else:
        weeks_r = m-1
weeks = weeks_l

for i in range(3):
    A[i] -= week[i]*weeks

besta = -1
for start_day in range(7):
    i = start_day
    B = A[:]
    while all(b>=0 for b in B):
        B[foods[i%7]] -= 1
        i += 1
    i -= 1
    if i-start_day>=besta:
        besta = i-start_day
cout << besta + weeks*7 << endl;