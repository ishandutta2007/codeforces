

base = 100000+1
mod = MOD = 10**9+7

from __pypy__ import intop

int_add = intop.int_add
int_sub = intop.int_sub
int_prod = intop.int_mul

MOD_inv = 1.0/MOD

def modprod(a,b,c=0):
    d = int_sub(int_add(int_prod(a,b),c), int_prod(MOD, int(MOD_inv*(1.0*a*b + c))))
    if d>=MOD: return d - MOD
    elif d<0: return d + MOD
    return d

def pow(a,b,MOD):
    c = 1
    if b==0: return c
    while b>1:
        if b&1:
            c = modprod(c,a)
        a = modprod(a,a)
        b //= 2
    return modprod(c,a)


def main():
    inp = readnumbers()
    ii = 0
    
    n,m = inp[ii],inp[ii+1]
    ii += 2
    
    orig = set()
    A = [0]*n
    for _ in range(m):
        a,b = inp[ii]-1, inp[ii+1]-1
        ii += 2
        if a>b:
            a,b = b,a
        
        orig.add((a,b))
        l = b-a
        l = min(l, n - l)
        
        hasher = pow(base,l,MOD)
        A[a] = (A[a] + hasher)%MOD
        A[b] = (A[b] + hasher)%MOD
    
    A += A

    cur_hash = 0
    for i in range(n):
        cur_hash = modprod(cur_hash,base,A[i])

    goal_hash = cur_hash
    pos = []
    for i in range(1,n):
        cur_hash = (cur_hash - modprod(A[i-1],pow(base,n-1,MOD)))%MOD
        cur_hash = modprod(cur_hash,base,A[i+n-1])
       
        if cur_hash == goal_hash:
            pos.append(i)
    
    for div in pos:
        ii = 2
        newtest = set()
        for _ in range(m):
            a,b = inp[ii]-1, inp[ii+1]-1
            ii += 2

            a = (a + div)%n
            b = (b + div)%n

            if a>b:
                a,b = b,a
            
            newtest.add((a,b))
        if newtest==orig:
            print 'Yes'
            sys.exit()
    print 'No'



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