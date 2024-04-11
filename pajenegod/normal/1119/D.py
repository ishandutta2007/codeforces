from __future__ import print_function
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

def mergesort(A, ls_cmp=None):
    if ls_cmp is None:
        ls_cmp = lambda i,j: i<j

    B, n = A[:], len(A)
    for i in range(0,n-1,2):
        if ls_cmp(A[i^1],A[i]):
            A[i],A[i^1] = A[i^1],A[i]
    width = 2
    while width < n:
        for i in range(0,n, 2*width):
            R1 = j = min(i + width, n) 
            R2 = min(i + 2 * width, n)
            k = i
            while i<R1 and j<R2:
                if ls_cmp(A[i],A[j]):
                    B[k] = A[i]
                    i += 1
                else:
                    B[k] = A[j]
                    j += 1
                k += 1
            while i<R1:
                B[k] = A[i]
                k += 1
                i += 1
            while k<R2:
                B[k] = A[k]
                k += 1
        A,B = B,A
        width *= 2
    return A

################## CODE

import _numpypy
zero = _numpypy.multiarray.dtype('int64').type()

inp = sys.stdin.readnumbers(zero)
ii = 0

n = int(inp[ii])
ii += 1
S = inp[ii:ii+n]
ii += n
S = mergesort(S)
pairs = mergesort([S[j+1]-S[j] for j in range(n-1)])

q = int(inp[ii])
ii += 1
Q = [inp[ii+2*i+1]-inp[ii+2*i] for i in range(q)]
ii += 2*q

my_cmp_lt = lambda i,j:Q[i]<Q[j]
order = mergesort(list(range(q)),my_cmp_lt)

out = [0]*q

j = 0
score = zero
for qi in order:
    while j < len(pairs) and pairs[j] <= Q[qi]: 
        score += pairs[j]
        j += 1

    out[qi] = score + (len(S)-j)*(Q[qi]+1)
print(*out)