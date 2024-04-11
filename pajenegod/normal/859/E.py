MOD = 10**9+7

def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1

    coupl = [[] for _ in range(2*n)]
    for _ in range(n):
        u = inp[ii] - 1
        ii += 1
        v = inp[ii] - 1
        ii += 1
        
        if u != v:
            coupl[u].append(v)

    scc,top = SCC(coupl)
    counter = [0]*(2*n)
    for i in range(2*n):
        counter[scc[i]] += 1
    
    ends_at = [x for x in range(2*n)]
    for i in range(2*n):
        if counter[scc[i]] > 1:
            ends_at[i] = -1
    
    
    ii = 1
    for _ in range(n):
        u = inp[ii] - 1
        ii += 1
        v = inp[ii] - 1
        ii += 1
        
        if u == v:
            counter[scc[u]] = -1
            ends_at[u] = -1

    rotations = 0
    for i in range(2*n):
        if counter[i]>1:
            rotations += 1
    
    for i in reversed(top):
        if ends_at[i]>=0 and coupl[i]:
            ends_at[i] = ends_at[coupl[i][0]]

    counter2 = [0]*(2*n)
    for i in range(2*n):
        if ends_at[i]>=0:
            counter2[ends_at[i]] += 1

    comb = pow(2,rotations,MOD)
    for i in range(2*n):
        if counter2[i]>0:
            comb = comb * (counter2[i]) % MOD
    print comb


def SCC(coupl):
    """
    Finds what strongly connected components each node
    is a part of in a directed graph, 
    it also finds a weak topological ordering of the nodes
    """
    n = len(coupl)
    comp = [-1]*n
    top_order = []

    Q = []
    stack = []
    new_node = None
    for root in range(n):
        if comp[root] >= 0: continue

        # Do a dfs while keeping track of depth
        Q.append(root)
        root_depth = len(top_order)
        while Q:
            node = Q.pop()
            if node>=0:
                if comp[node] >= 0: continue
                # First time

                # Index the node
                comp[node] = len(top_order) + len(stack)
                stack.append(node)
                
                # Do a dfs
                Q.append(~node)
                Q += coupl[node]
            else:
                # Second time
                node = ~node
                
                # calc low link
                low = index = comp[node]
                for nei in coupl[node]:
                    if root_depth <= comp[nei]:
                        low = min(low, comp[nei])
                
                # low link same as index, so create SCC
                if low == index:
                    while new_node != node:
                        new_node = stack.pop()
                        comp[new_node] = index
                        top_order.append(new_node)
                else:
                    comp[node] = low
    top_order.reverse()
    return comp, top_order

######## Python 2 and 3 footer by Pajenegod and c1729

# Note because cf runs old PyPy3 version which doesn't have the sped up
# unicode strings, PyPy3 strings will many times be slower than pypy2.
# There is a way to get around this by using binary strings in PyPy3
# but its syntax is different which makes it kind of a mess to use.

# So on cf, use PyPy2 for best string performance.

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)

class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

# Cout implemented in Python
import sys
class ostream:
    def __lshift__(self,a):
        sys.stdout.write(str(a))
        return self
cout = ostream()
endl = '\n'

# Read all remaining integers in stdin, type is given by optional argument, this is fast
def readnumbers(zero = 0):
    conv = ord if py2 else lambda x:x
    A = []; numb = zero; sign = 1; i = 0; s = sys.stdin.buffer.read()
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