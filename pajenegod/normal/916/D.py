import sys, os, __pypy__
from collections import defaultdict
from cStringIO import StringIO
from io import IOBase
range = xrange
input = raw_input
 
L = []
R = []
A = [0]

__pypy__.resizelist_hint(L, 50*10**5)
__pypy__.resizelist_hint(R, 50*10**5)
__pypy__.resizelist_hint(A, 50*10**5)


def create():
    L.append(-1)
    R.append(-1)
    A.append(0)
    return len(L) - 1
 
def copy(ind):
    L.append(L[ind])
    R.append(R[ind])
    A[-1] = A[ind]
    A.append(0)
    return len(L) - 1
 
def adder(i, n, ind, x):
    ind0 = ind = copy(ind) if ind >= 0 else create()
    while n != 1:
        A[ind] += x
        n = n >> 1
        if i < n:
            L[ind] = ind = copy(L[ind]) if L[ind] >= 0 else create()
        else:
            R[ind] = ind = copy(R[ind]) if R[ind] >= 0 else create()
            i -= n
    A[ind] += x
    return ind0
 
def getter(r, n, ind):
    ans = 0
    while ind >= 0 and 0 < r:
        if r >= n:
            ans += A[ind]
            break
        n = n >> 1
        ans += getter(r - n, n, R[ind])
        ind = L[ind]
    return ans

def getteri(i, n, ind):
    ans = 0
    while ind >= 0:
        if n == 1:
            return A[ind]
        n = n >> 1
        if i < n:
            ind = L[ind]
        else:
            i -= n
            ind = R[ind]
    return 0
 
mapper = {'set':0, 'remove':1, 'query':2, 'undo':3}
N = 1 << 30
M = 1 << 17
 
def main():
    curbucket = -1
    curprio   = -1
    Tbucket = [curbucket]
    Tprio   = [curprio]
    identifier = defaultdict(lambda: len(identifier))
 
    q = int(input())
    for curd in range(q):
        inp = sys.stdin.readline().split(); ii = 0
        cas = mapper[inp[ii]]; ii += 1
        if cas == 0:
            aind = identifier[inp[ii]]; ii += 1
            new_prio = int(inp[ii]); ii += 1
 
            prio = getteri(aind, M, curprio)
            curprio = adder(aind, M, curprio, new_prio - prio)
            if prio:
                curbucket = adder(prio, N, curbucket, -1)
            if new_prio:
                curbucket = adder(new_prio, N, curbucket, 1)
        elif cas == 1:
            aind = identifier[inp[ii]]; ii += 1
            prio = getteri(aind, M, curprio)
            if prio:
                curbucket = adder(prio, N, curbucket, -1)
                curprio = adder(aind, M, curprio, -prio)
        elif cas == 2:
            aind = identifier[inp[ii]]; ii += 1
            prio = getteri(aind, M, curprio)
            ans = getter(prio, N, curbucket) if prio else -1
            os.write(1, str(ans) + '\n')
        else: #  cas == 3
            d = int(inp[ii]); ii += 1
            curbucket = Tbucket[curd - d]
            curprio   = Tprio[curd - d]
        Tbucket.append(curbucket)
        Tprio.append(curprio)
 
# region fastio
 
BUFSIZE = 8192
 
class FastI(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = StringIO()
        self.newlines = 0
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count("\n") + (not b)
            ptr = self._buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines -= 1
        return self._buffer.readline()
 
 
class FastO(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = __pypy__.builders.StringBuilder()
        self.write = lambda s: self._buffer.append(s)
 
    def flush(self):
        os.write(self._fd, self._buffer.build())
        self._buffer = __pypy__.builders.StringBuilder()
 
sys.stdin, sys.stdout = FastI(sys.stdin), FastO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
 
if __name__ == "__main__":
    main()