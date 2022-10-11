# Not my code https://codeforces.com/contest/1616/submission/141185703
 
class SegmentTree:
    def __init__(self, data, default=0, func=max):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def __delitem__(self, idx):
        self[idx] = self._default
 
    def __getitem__(self, idx):
        return self.data[idx + self._size]
 
    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def __len__(self):
        return self._len
 
    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size
 
        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1
 
        return self._func(res_left, res_right)
 
    def find(self, x):
        curr = 1
        #assert self.data[0] == self.data[1]
        if self.data[curr] > x:
            return -1
        while curr < self._size:
            assert self.data[curr] <= x
            if self.data[2 * curr] <= x:
                curr = 2 * curr
            else:
                curr = 2 * curr + 1
            assert self.data[curr] <= x
        return curr - self._size
 
    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
    
import os
import sys
from io import BytesIO, IOBase
 
_str = str
str = lambda x=b"": x if type(x) is bytes else _str(x).encode()
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._file = file
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
 
t = int(input())
out = []
 
chars = SegmentTree([28] * 100000, default = 28, func=min)
ex = SegmentTree([0] * 100000, default = 0, func=lambda x, y: x + y)
    
    
for _ in range(t):
    n = int(input())
    #s = [98] * ((n//2) - 1) + [97] * ((n//2) + 1) #input().strip()
    #t = [97] * (n//2 - 0) + [98] * (n//2 + 0)#input().strip()
    s = input().strip()
    t = input().strip()
 
    #chars = SegmentTree([ord(c) - 97 for c in s], default = 28, func=min)
    for i in range(n):
        chars[i] = ord(s[i]) - 97
        ex[i] = 1
    #ex = SegmentTree([1 for c in s], default = 0, func=lambda x, y: x + y)
 
    poss = []
    curr = float(0)
    for c in t:
        v = ord(c) - 97
 
        #Finish
        x = chars.find(v - 1)
        if x != -1:
            poss.append(curr + ex.query(0, x))
 
        #MTF
        x = chars.find(v)
        if x != -1:
            curr += ex.query(0, x)
            ex[x] = 0
            chars[x] = 28
        else:
            break
    if poss:
        out.append((min(poss)))
    else:
        out.append(-1)
        
    for i in range(n):
        chars[i] = 28
outS = '\n'.join(map(lambda x: _str(int(x)), out))
print(outS)