def main():
    inp = readnumbers()
    ii = 0

    n = inp[ii]
    ii += 1
    
    m = inp[ii]
    ii += 1

    coupl = [[] for _ in range(n)]
    for _ in range(m):
        u = inp[ii] - 1
        ii += 1
        v = inp[ii] - 1
        ii += 1

        coupl[u].append(v)
        coupl[v].append(u)
    
    s = inp[ii]
    ii += 1
    b = inp[ii]
    ii += 1
    k = inp[ii]
    ii += 1
    h = inp[ii]
    ii += 1

    ii += 3*s
    
    bases = [[] for _ in range(n)]
    D = []

    for ind in range(b):
        x = inp[ii] - 1
        ii += 1
        d  = inp[ii]
        ii += 1
        D.append(d)
        bases[x].append(ind)
    
    ii -= 2 * b + 3 * s

    spaces = [[] for _ in range(s)]
    for ind in range(s):
        x = inp[ii] - 1
        ii += 1
        a = inp[ii]
        ii += 1
        f = inp[ii]
        ii += 1

        dist = [-1]*n
        dist[x] = 0

        bfs = [x]
        for node in bfs:
            for bind in bases[node]:
                if D[bind] <= a:
                    spaces[ind].append(bind)
            d = dist[node]
            if d < f:
                for nei in coupl[node]:
                    if dist[nei] == -1:
                        bfs.append(nei)
                        dist[nei] = d + 1
    source = s + b
    sink = s + b + 1
    U = []
    V = []
    C = []
    coupl = [[] for _ in range(s+b+2)]
    for ind in range(s):
        for bases in spaces[ind]:
            coupl[ind].append(len(U))
            U.append(ind)
            V.append(s + bases)
            C.append(1)
        
        coupl[source].append(len(U))
        U.append(source)
        V.append(ind)           
        C.append(1)

    for bases in range(b):
        coupl[bases + s].append(len(U))
        U.append(bases + s)
        V.append(sink)           
        C.append(1)

    maxflow, flows = dinics_maxflow(coupl, U, V, C, source, sink, lim = 1, directed = True)
   

    bestcost = 10**18
    matched = maxflow
    unused = s - matched
    
    fake = 0
    while fake <= s:
        bestcost = min(bestcost, k * matched + h * fake)
        if unused:
            unused -= 1
        elif matched:
            matched -= 1
        fake += 1
    print bestcost


# _coupl[node] should contain the indices of all edges going from node
# _U[e] = start node of edge with index e
# _V[e] = end node of edge with index e
# _C[e] = capacity of edge with index e
# s source
# t target (sink)
# lim, set to 2**30 to turn on dini'c with scaling, it is turned off by default 
# directed, allows flow in both directions
 
def dinics_maxflow(_coupl, _U, _V, _C, s, t, lim = 1, directed = False):
    assert(len(_U) == len(_V) == len(_C))
    n = len(_coupl)
    m = len(_U)
    total_flow = 0
    
    
    # Add in the backward edges
    # Even edge index is forward edge
    # Odd edge index is backward edge
    coupl = [[2*i for i in c] for c in _coupl]
 
    V = []
    for i in range(m):
        V.append(_V[i])
        V.append(_U[i])
    
    C = []
    if directed:
        for i in range(m):
            C.append(_C[i])
            C.append(0)
    else:
        for i in range(m):
            C.append(_C[i])
            C.append(_C[i])
    for i in range(m):
        coupl[V[2*i]].append(2*i^1) 
    
    inf = sum(C[e] for e in coupl[s] if V[e^1]==s)
    ptr_copy = [len(coupl[i]) - 1 for i in range(n)]
 
    while True:
        # Calculate distance from source using all edges with cap >= lim
        dist_to_source = [0]*n
        dist_to_source[s] = 1
        bfs = [s]
        for node in bfs:
            if dist_to_source[t]:
                break
            my_dist_plus_1 = dist_to_source[node] + 1
            for e in coupl[node]:
                if not dist_to_source[V[e]] and C[e] >= lim:
                    dist_to_source[V[e]] = my_dist_plus_1
                    bfs.append(V[e])
 
        if not dist_to_source[t]:
            lim //= 2
            if lim == 0:
                break
            continue
        # Find the blocking flows
 
        # Note this is natural to be implemented with a recursive dfs
        # But because this is python I'm instead using an iterative
        # solution
        ptr = ptr_copy[:]
        stack = [0]*(2*n+1)
        stack[0] = s
        stack[1] = inf
        stack[2] = s
        ii = 1
        while ptr[s] >= 0:
            cap = stack[ii]
            node = stack[ii + 1]

            if node == t:
                total_flow += cap
                for node in stack[2:ii:2]:
                    e = coupl[node][ptr[node]]
                    C[e] -= cap
                    C[e^1] += cap
                ii = 1
                continue
            
            # Do recursive call
            edges = coupl[node]
            count = ptr[node]
            mydist_plus_1 = dist_to_source[node] + 1
            while count >= 0:
                e = edges[count]
                if dist_to_source[V[e]] == mydist_plus_1 and C[e] > 0:
                    ii += 2
                    stack[ii] = C[e] if C[e] < cap else cap
                    stack[ii+1] = V[e]
                    break
                count -= 1
            else:
                ii -= 2
                ptr[stack[ii + 1]] -= 1
            ptr[node] = count
    if directed:
        flows = C[1::2]
    else:
        flows = []
        for i in range(m):
            flows.append((C[2*i^1] - C[2*i])//2)
    maxflow = total_flow
    return maxflow, flows


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