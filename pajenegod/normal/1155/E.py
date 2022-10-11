from __pypy__ import intop

int_add = intop.int_add
int_sub = intop.int_sub
int_prod = intop.int_mul

MOD = 10**6 + 3
MOD_inv = 1.0/MOD

def modprod(a,b,c=0):
    d = int_sub(int_add(int_prod(a,b),c), int_prod(MOD, int(MOD_inv*(1.0*a*b + c))))
    if d>=MOD: return d - MOD
    elif d<0: return d + MOD
    return d
    
MOD = 10**6+3

def conv(A,B):
    n = len(A)
    m = len(B)
    C = [0]*(n+m-1)
    for i in range(n):
        for j in range(m):
            C[i+j] = modprod(A[i],B[j],C[i+j])
    return C

def add(A,B):
    n = max(len(A),len(B))
    C = [0]*n
    for i,a in enumerate(A):
        C[i] = (C[i] + a)%MOD
    for i,b in enumerate(B):
        C[i] = (C[i] + b)%MOD
    return C

def main():
    f = {}
    for x in range(11):
        print '?',x
        sys.stdout.flush()
        f[x] = int(input())
    
    # Interpolate the pol using Langrages interpolation
    P = []
    for x in range(11):
        fac = f[x]
        for k in range(11):
            if k!=x:
                fac = modprod(fac, pow(x - k, MOD-2, MOD))

        pol = [fac]
        for k in range(11):
            if k!=x:
                pol = conv(pol, [-k, 1])
        P = add(P, pol)
    
    # Knowing the poly P, just bruteforce the rest
    X = [1]*11
    for x0 in range(MOD):
        X[0] = 1
        for i in range(1,11):
            X[i] = modprod(x0,X[i-1])

        numb = 0
        for i in range(11):
            numb = modprod(P[i],X[i],numb)
        
        # if root found
        if numb==0:
            print '!',x0
            sys.exit()
    print '!',-1
    


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