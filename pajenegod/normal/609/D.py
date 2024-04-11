#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#pragma GCC optimize ("O3")
#pragma GCC target ("avx,avx2")


from __future__ import division, print_function
py2 = round(0.5)

if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange

def sync_with_stdio(b):
    if b: return
    import os, sys
    from io import IOBase, BytesIO
    
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
    global input
    input = sys.stdin.input


import sys

class ostream:
    def __lshift__(self,a):
        if a == endl:
            sys.stdout.write('\n')
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



######## PYTHON++ ########
sync_with_stdio(False);
cin.tie(0); cout.tie(0);

n = m = k = s = 0;
n <<= cin;
m <<= cin;
k <<= cin;
s <<= cin;

A = vector<<int>>(n);
A <<= cin;
B = vector<<int>>(n);
B <<= cin;

T = vector<<bool>>(0);
C = vector<<int>>(0);
for _ in range(m):
    typ = 0;
    cost = 0;
    typ <<= cin;
    cost <<= cin;
    T.append(typ==1);
    C.append(cost);
    
a = 1;
b = n+1;
while (a<b):
    c = (a+b)//2;
    dmin = min(A[:c]);
    pmin = min(B[:c]);
    costs = sorted((dmin if T[i] else pmin)*C[i] for i in range(m))[:k];
    
    if (sum(costs) <= s):
        b = c;
    else:
        a = c + 1;

if (a == n+1):
    cout << -1 << endl;
else:
    dayd = min(range(a), key = lambda i: A[i]);
    dayp = min(range(a), key = lambda i: B[i]);
    dmin = A[dayd];
    pmin = B[dayp];
    
    indecies = sorted(range(m), key = lambda i: (dmin if T[i] else pmin)*C[i])[:k];
    cout << a << '\n';
    for i in indecies:
        cout << i+1 << " ";
        if T[i]==1:
            cout << dayd+1 << '\n';
        else:
            cout << dayp+1 << '\n';