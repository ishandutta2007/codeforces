#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip
else:
    _str = str
    str = lambda x=b"": x if type(x) is bytes else _str(x).encode()


class SegmentTree:
    def __init__(self, data, default=0, func=lambda x, y: max(x, y)):
        """initialize the segment tree with data"""
        self._len = _len = len(data)
        self._size = _size = 1 << (_len - 1).bit_length()
        self._data = _data = [default] * (2 * _size)
        self._default = default
        self._func = func
        _data[_size:_size + _len] = data
        for i in reversed(range(_size)):
            _data[i] = func(_data[2 * i], _data[2 * i + 1])

    def __delitem__(self, key):
        self[key] = self._default

    def __getitem__(self, key):
        return self._data[key + self._size]

    def __setitem__(self, key, value):
        key += self._size
        while key:
            self._data[key] = value
            value = self._func(value, self._data[key^1])
            key >>= 1

    def __len__(self):
        return self._len

    def bisect_left(self, value):
        i = 1
        while i < self._size:
            i = 2 * i + 1 if value > self._data[2 * i] else 2 * i
        return i - self._size

    def bisect_right(self, value):
        i = 1
        while i < self._size:
            i = 2 * i + 1 if value >= self._data[2 * i] else 2 * i
        return i - self._size

    bisect = bisect_right

    def query(self, begin, end):
        begin += self._size
        end += self._size
        res = self._default

        while begin < end:
            if begin & 1:
                res = self._func(res, self._data[begin])
                begin += 1
            if end & 1:
                end -= 1
                res = self._func(res, self._data[end])
            begin >>= 1
            end >>= 1

        return res


def main():
    n = int(readline())
    a = map(int, input().split())
    b = SegmentTree(sorted(map(int, input().split())), -1)

    start = 0
    for ai in a:
        idx = b.bisect_left(n - ai)
        if b[idx] < n - ai:
            idx = start
            while b[idx] == -1:
                idx += 1
            start = idx
        cout << (b[idx] + ai) % n << ' '
        del b[idx]
    cout << '\n'


# region template

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


class ostream:
    def __lshift__(self, a):
        if a is endl:
            sys.stdout.write(b"\n")
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


sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
cout, endl = ostream(), object()

readline = sys.stdin.readline
readlist = lambda var=int: [var(n) for n in readline().split()]
input = lambda: readline().rstrip(b"\r\n")

# endregion

if __name__ == "__main__":
    main()