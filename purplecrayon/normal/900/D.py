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


x, y = map(int, input().split(' '))

if y % x != 0:
    print(0)
    quit()

y = y // x

# sum = y, gcd = 1
# mobius function, you only care about divisors of y

def prime(c):
    d = 2
    p = []
    Y = y
    while d * d <= Y:
        if Y % d == 0:
            p.append(d)
        while Y % d == 0:
            Y = Y // d
        d += 1

    if Y > 1:
        p.append(Y)

    return p

MOD = 10 ** 9 + 7

def f(c):
    # number of arrays s.t. all numbers are a multiple of c and the sum is y
    assert y % c == 0
    s = y // c
    # number of arrays with sum s, s.t. each number is positive
    # 2**(s-1)
    
    return pow(2, s-1, MOD)

ans = 0 

p = prime(y)
for mask in range(1 << len(p)):
    c = 1
    for i in range(len(p)):
        if ((mask >> i) & 1) > 0:
            c *= p[i]

    pct = bin(mask).count("1")
    if pct % 2 == 0:
        ans += f(c)
    else:
        ans -= f(c)

    ans = ans % MOD

print(ans)