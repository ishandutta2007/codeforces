# NOT MY CODE
# https://codeforces.com/contest/1144/submission/84914057
import os
import sys
from io import BytesIO, IOBase

# bootstrapper
from types import GeneratorType

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


# region fastio
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
MOD = 1000000007
ii = lambda :  int(input())
si = lambda :  input()
dgl = lambda : list(map(int, input()))
f = lambda :   map(int, input().split())
il = lambda :  list(map(int, input().split()))
ls = lambda :  list(input())
from collections import defaultdict
import sys
n,m=f()
@bootstrap
def dfs(node,c=0):
    v[node]=1
    co[node]=c
    for j in g[node]:
        if(v[j]==0):
            if((yield dfs(j,c^1)) == False):
                yield False
        else:
            if(co[node]==co[j]):
                yield False
    yield True
g=defaultdict(list)
u=[0]*(200000+1)
for i in range(1,m+1):
    a,b=f()
    u[i]=a
    g[a].append(b)
    g[b].append(a)
v=[0]*(200000+1)
co=[0]*(200000+1)
if(dfs(1,0)):
    print("YES")
    for i in range(1,m+1):
        if(co[u[i]]==0):
            print(0,end='')
        else:
            print(1,end='')
else:
    print("NO")