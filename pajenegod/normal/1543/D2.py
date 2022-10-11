# Not my code https://codeforces.com/blog/entry/92648
 
#!/usr/bin/env python
 
import os
import sys
from io import BytesIO, IOBase
    
def sub(a,b,k):
    su,po = 0,1
    while a or b:
        su += (a-b)%k*po
        a //= k
        b //= k
        po *= k
    return su
 
def add(a,b,k):
    su,po = 0,1
    while a or b:
        su += (a+b)%k*po
        a //= k
        b //= k
        po *= k
    return su
 
def main():
    for _ in range(int(input())):
        n,k = map(int,input().split())
        curr = 0
        occ = 0
        for i in range(n):
            if i&1:
                ask = sub(curr,i,k)
            else:
                ask = add(curr,i,k)
            os.write(1, str(ask).encode('ascii') + b'\n')
            r = int(input())
            if r == 1:
                break
            curr = sub(ask,curr,k)
            occ += 1
 
# region fastio
 
BUFSIZE = 1000
 
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
 
 
if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
 
input = sys.stdin.buffer.readline
 
# endregion
 
if __name__ == "__main__":
    main()