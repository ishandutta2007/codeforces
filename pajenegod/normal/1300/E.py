from math import factorial
from collections import Counter
from heapq import heapify, heappop, heappush
from sys import stdin
def RL(): return map(int, stdin.readline().rstrip().split() )
def comb(n, m): return factorial(n)/(factorial(m)*factorial(n-m)) if n>=m else 0
def perm(n, m): return factorial(n)//(factorial(n-m)) if n>=m else 0
def mdis(x1, y1, x2, y2): return abs(x1-x2) + abs(y1-y2)
mod = 1000000007
INF = float('inf')
 
# ------------------------------
 
def main():
    n = int(input())
    arr = [int(i) for i in input().split()]
     
    sm = [0.0]
    for i in arr: sm.append(sm[-1]+i)
     
    # mean = lambda a, b: (sm[b]-sm[a])/(b-a)
    def mean(t):
        i, j = t
        return (sm[j] - sm[i]) / (j - i)
     
    stack = []
     
    for i in range(n):
        # print(stack)
        stack.append((i, i+1))
     
        while len(stack)>1 and mean(stack[-2])>=mean(stack[-1]):
            a, b = stack.pop()
            c, d = stack.pop()
            stack.append((c, b))
     
    res = [0.0]*n
    for n, v in stack:
        m = mean((n, v))
        for i in range(n, v):
            res[i] = m
    print(*res)
 
# https://github.com/cheran-senthil/PyRival/blob/master/templates/template_py3.py
import os
import sys
from io import BytesIO, IOBase
 
 
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
 
# endregion
 
if __name__ == "__main__":
    main()