py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

def sync_with_stdio(b):
    if b: return
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
            while self.bufendl == 0: s = self.read2buffer(); self.bufendl += s.count(b"\n") + (not s)
            self.bufendl -= 1; return self.stream.readline()
        def input(self): return self.readline().rstrip(b'\r\n')
        
        # Read all remaining integers, type is given by optional argument
        def readnumbers(self, zero=0):
            conv = ord if py2 else lambda x:x
            A = []; numb = zero; sign = 1; c = b"-"[0]
            for c in self.read():
                if c >= b"0"[0]: numb = 10 * numb + conv(c) - 48
                elif c == b"-"[0]: sign = -1
                elif c != b"\r"[0]: A.append(sign*numb); numb = zero; sign = 1
            if c >= b"0"[0]: A.append(sign*numb)
            return A
    
    class FastO(IOBase):
        def __init__(self, fd=1):
            stream = BytesIO()
            self.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
            self.write = stream.write if py2 else lambda s: stream.write(s.encode())
    
    sys.stdin, sys.stdout = FastI(), FastO()
    global input
    input = sys.stdin.input


import sys

class ostream:
    def __lshift__(self,a):
        if a == endl:
            sys.stdout.write("\n")
            sys.stdout.flush()
        else:
            sys.stdout.write(str(a))
        return self
    def tie(self, val):pass
cout = ostream()
endl = object()

class istream:
    tiedto = cout
    inp = None
    def __rlshift__(a,b):
        if a.tiedto == cout:
            sys.stdout.flush()
        if type(b)==tuple or type(b)==list:
            return type(b)(type(c)(a.get()) for c in b)
        return type(b)(a.get())
    def tie(self, val):
        self.tiedto = val
    def get(a):
        while not a.inp:
            a.inp = sys.stdin.readline().split()[::-1]
        return a.inp.pop()
cin = istream()

class Vector:
    def __lshift__(self, other):
        self.type = other
        return self
    def __rshift__(self, other):
        if type(other) == tuple:
            return [self.type(other[1])]*other[0]
        else:
            return [self.type()]*other
vector = Vector()

sync_with_stdio(False);
cin.tie(0); cout.tie(0);



########################## PERSISTENT SEGMENTTREE (surprisingly good memory effecient)

BIG = 10**9

vals = []
L = []
R = []

# Create a persistant segmenttree of size n
def create(n):
    ind = len(vals)
    vals.append(BIG)
    
    L.append(-1)
    R.append(-1)
    
    if n==1:
        L[ind] = -1
        R[ind] = -1
    else:
        mid = n//2
        L[ind] = create(mid)
        R[ind] = create(n - mid)
    return ind

# Set seg[i]=val for segment tree ind, of size n,
def setter(ind, i, val, n):
    ind2 = len(vals)
    vals.append(BIG)
    L.append(-1)
    R.append(-1)
    
    if n==1:
        vals[ind2] = val
        return ind2
    
    mid = n//2 
    if i < mid:
        L[ind2] = setter(L[ind], i, val, mid)
        R[ind2] = R[ind]
    else:
        L[ind2] = L[ind]
        R[ind2] = setter(R[ind], i - mid, val, n - mid)
    
    vals[ind2] = min(vals[L[ind2]], vals[R[ind2]])
    return ind2

# Find minimum of seg[l:r] for segment tree ind, of size n
def minimum(ind, l, r, n):
    if l==0 and r==n:
        return vals[ind]
    mid = n//2
    if r <= mid:
        return minimum(L[ind], l, r, mid)
    elif mid<=l:
        return minimum(R[ind], l - mid, r - mid, n - mid)
    else:
        return min( minimum(L[ind], l, mid, mid), minimum(R[ind], 0, r - mid, n - mid))

######################################################################

import sys
inp = sys.stdin.readnumbers()
ii = 0

n = inp[ii]
ii += 1

r = inp[ii]-1
ii += 1

A = inp[ii:ii+n]
ii += n

coupl = [[] for _ in range(n)]
for _ in range(n-1):
    x,y = inp[ii]-1, inp[ii+1]-1
    ii += 2
    coupl[x].append(y)
    coupl[y].append(x)


# Start reordering the nodes after DFS ordering

found = [False]*n

found[r] = True
Qdum = [r]
Q = []
while Qdum:
    node = Qdum.pop()
    Q.append(node)
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = True
            Qdum.append(nei)



mapper = [-1]*n
for i,node in enumerate(Q):
    mapper[node] = i

couplprim = []
for node in range(n):
    couplprim.append([mapper[nei] for nei in coupl[Q[node]]])

rprim = 0
assert(rprim == mapper[r])

Aprim = [A[Q[i]] for i in range(n)]

# Nodes has been reordered, now figure out some DFS stuff like dfs, family size
depth = [-1]*n
family_size = [0]*n

depth[rprim] = 0
Qprim = [rprim]
first_time = [True]*n

while Qprim:
    node = Qprim.pop()
    
    if first_time[node]:
        first_time[node] = False
        Qprim.append(node)
        
        for nei in couplprim[node]:
            if depth[nei] == -1:
                depth[nei] = depth[node]+1
                Qprim.append(nei)
    else:
        f = 1
        for nei in couplprim[node]:
            f += family_size[nei]
        family_size[node] = f

# Time to bucket sort the nodes in order of depth
D = [[] for _ in range(2*n)]

for node in range(n):
    D[depth[node]].append(node)


##################### PERSISTENT SEGMENT TREE PART
# So simple, yet so much going on


Dseg = [0]*(2*n)
ind = create(n)

for i,nodes in enumerate(D):
    for node in nodes:
        ind = setter(ind, node, Aprim[node], n)
    Dseg[i] = ind

#############################

m = inp[ii]
ii += 1

ans = 0
for _ in range(m):
    p = inp[ii]
    ii += 1
    q = inp[ii]
    ii += 1

    x = mapper[(p + ans)%n]
    k = (q + ans)%n
    
    ans = minimum(Dseg[depth[x]+k], x, x + family_size[x], n)
    cout << ans << "\n"