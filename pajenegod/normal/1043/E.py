#!/usr/bin/env python
from __future__ import division, print_function

# Testing c1729's code

import os
import sys
from io import BytesIO, IOBase

import _random

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
else:
    _str = str
    str = lambda x=b"": x if type(x) is bytes else _str(x).encode()


def sorted(iterable, key=lambda x: x, reverse=False):
    C = [key(a) for a in iterable]
    A = iterable
    B = A[:]
    n = len(A)

    for i in range(0, n - 1, 2):
        if C[A[i]] > C[A[i ^ 1]]:
            A[i], A[i ^ 1] = A[i ^ 1], A[i]

    width = 2
    while width < n:
        for i in range(0, n, 2 * width):
            R1, R2 = min(i + width, n), min(i + 2 * width, n)
            j, k = R1, i

            while i < R1 and j < R2:
                if C[A[i]] > C[A[j]]:
                    B[k] = A[j]
                    j += 1
                else:
                    B[k] = A[i]
                    i += 1
                k += 1

            while i < R1:
                B[k] = A[i]
                k += 1
                i += 1

            while k < R2:
                B[k] = A[k]
                k += 1

        A, B = B, A
        width *= 2

    if reverse:
        A.reverse()

    return A


def main():
    n, m = readarr()
    a = [readarr() + [i] for i in range(n)]
    c = [0] * n
    for _ in range(m):
        x, y = readarr()
        s = min(a[x - 1][0] + a[y - 1][1], a[x - 1][1] + a[y - 1][0])
        c[x - 1] -= s
        c[y - 1] -= s

    order = sorted(list(range(n)), key=lambda i: a[i][1] - a[i][0])
    sum_x = sum(i[0] for i in a)
    sum_y = 0

    for i in range(n):
        j = order[i]
        sum_x -= a[j][0]
        c[a[j][2]] += sum_x + ((n - i - 1) * a[j][1]) + sum_y + (i * a[j][0])
        sum_y += a[j][1]

    print(*c)


BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._buffer = BytesIO()
        self._fd = file.fileno()
        self._writable = "x" in file.mode or "r" not in file.mode
        self.write = self._buffer.write if self._writable else None

    def read(self):
        if self._buffer.tell():
            return self._buffer.read()
        return os.read(self._fd, os.fstat(self._fd).st_size)

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self._buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines -= 1
        return self._buffer.readline()

    def flush(self):
        if self._writable:
            os.write(self._fd, self._buffer.getvalue())
            self._buffer.truncate(0), self._buffer.seek(0)


class Random(_random.Random):
    def shuffle(self, x):
        for i in range(len(x) - 1, 0, -1):
            j = int(self.random() * (i + 1))
            x[i], x[j] = x[j], x[i]

    randrange = lambda self, a, b, step=1: a + step * int(
        self.random() * ((b - a + step + [1, -1][step < 0]) // step)
    )
    randint = lambda self, a, b: a + int(self.random() * (b - a + 1))
    choice = lambda self, seq: seq[int(self.random() * len(seq))]


class ostream:
    def __lshift__(self, a):
        if a is endl:
            sys.stdout.write("\n")
            sys.stdout.flush()
        else:
            sys.stdout.write(str(a))
        return self


def print(*args, **kwargs):
    sep, file = kwargs.pop("sep", b" "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", b"\n"))
    if kwargs.pop("flush", False):
        file.flush()


input = lambda: sys.stdin.readline().rstrip(b"\r\n")
readnum = lambda var=int: var(sys.stdin.readline())
readarr = lambda var=int: [var(x) for x in sys.stdin.readline().split()]


random = Random()
sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
cout, endl = ostream(), object()


if __name__ == "__main__":
    main()