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

## Code

inp = sys.stdin.readnumbers()
ii = 0

n = inp[ii]
ii += 1
m = inp[ii]
ii += 1
k = inp[ii]
ii += 1

A = inp[ii:ii+n]
ii += n
A.sort(reverse=True)
A = A[-k:]


X = inp[ii::2]
Y = inp[ii+1::2]

# small is best buy of x shovels, and if x>k ignore them
small = [None]*(k+1)
for i in range(m):
    x = X[i]
    y = Y[i]
    if x>k:
        # Misha has to buy exactly k shovels
        pass
    else:
        if small[x] is None:
            small[x] = x-y
        else:
            small[x] = min(small[x],x-y)

Acumsum = [0]
for a in A:
    Acumsum.append(Acumsum[-1] + a)

DP = [0]*(k+1)

# How cheap can you buy k shovels
for i in range(1,k+1):
    besta = Acumsum[i]
    for j in range(i):
        
        if small[i-j] is not None:
            besta = min(besta, DP[j] + Acumsum[j+small[i-j]] - Acumsum[j])
        else:
            besta = min(besta, DP[j] + Acumsum[i] - Acumsum[j])
    DP[i] = besta

cout << DP[-1] << endl;