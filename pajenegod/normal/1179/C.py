#!/usr/bin/env pypy
from __future__ import division, print_function

import os
import sys
from __builtin__ import xrange as range
from cStringIO import StringIO
from future_builtins import ascii, filter, hex, map, oct, zip
from io import IOBase
import __pypy__

MAXN = 10**6 + 1


def main():
    n, m = map(int, input().split())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    c = [0] * MAXN
    for ai in a:
        c[ai] += 1
    for bi in b:
        c[bi] -= 1

    suff_sum = [0] * (MAXN + 1)
    for i in reversed(range(MAXN)):
        suff_sum[i] = suff_sum[i + 1] + c[i]
    segtree = LazySegmentTree(suff_sum)

    q = int(input())
    for _ in range(q):
        f, i, x = map(int, input().split())
        i -= 1

        if f == 1:
            segtree.add(0, a[i] + 1, -1)
            segtree.add(0, x + 1, 1)
            a[i] = x
        else:
            segtree.add(0, b[i] + 1, 1)
            segtree.add(0, x + 1, -1)
            b[i] = x

        print(segtree.bisect(0, lambda x, y: x < y))


class LazySegmentTree:
    def __init__(self, data, padding = 0, func=max):
        """initialize the lazy segment tree with data"""
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
        
        self.data = [padding] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(1, _size)):
            self.data[i] = func(self.data[2 * i], self.data[2 * i + 1])
        
        #TODO
        self._lazy = [0] * (2 * _size)

    def _push(self, idx):
        """push query on idx to its children"""
        # Let the children know of the queries
        # TODO
        q = self._lazy[idx]
        self._lazy[idx] = 0

        self._lazy[2 * idx] += q
        self._lazy[2 * idx + 1] += q

        self.data[2 * idx] += q
        self.data[2 * idx + 1] += q

    def _build(self, idx):
        """make the changes to idx be known to its ancestors"""
        idx >>= 1
        while idx:
            # TODO
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1]) + self._lazy[idx]
            idx >>= 1

    def _update(self, idx):
        """updates the node idx to know of all queries applied to it via its ancestors"""
        for i in reversed(range(1, idx.bit_length())):
            self._push(idx >> i)

    def add(self, start, stop, value):
        """lazily add value to [start, stop)"""
        start = start_copy = start + self._size
        stop = stop_copy = stop + self._size

        # Apply all the lazily stored queries
        self._update(start)
        self._update(stop - 1)
        
        while start < stop:
            if start & 1:
                self._lazy[start] += value
                self.data[start] += value
                start += 1
            if stop & 1:
                stop -= 1
                self._lazy[stop] += value
                self.data[stop] += value
            
            start >>= 1
            stop >>= 1
        
        self._build(start_copy)
        self._build(stop_copy - 1)

    def query(self, start, stop, default_if_empty = None):
        """func of data[start, stop)"""
        if start >= stop:
            return default_if_empty
        
        start += self._size
        stop += self._size

        # Apply all the lazily stored queries
        self._update(start)
        self._update(stop - 1)

        if start + 1 == stop:
            return self.data[start]

        res1 = self.data[start]
        res2 = self.data[stop - 1]
        start += 1
        stop -= 1
        while start < stop:
            if start & 1:
                res = self._func(res1, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(self.data[stop], res2)
            start >>= 1
            stop >>= 1
        return self._func(res1, res2)

    def node_size(self, idx):
        return 1 << self._size.bit_length() - idx.bit_length()
    
    def bisect(self, value, cmp):
        if not cmp(value, self.data[1]):
            return -1

        idx = 1
        while idx < self._size:
            self._push(idx)
            idx <<= 1
            if cmp(value, self.data[idx + 1]):
                idx += 1
        return idx - self._size

# region fastio

BUFSIZE = 8192


class FastI(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = StringIO()
        self.newlines = 0

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
            self.newlines = b.count("\n") + (not b)
            ptr = self._buffer.tell()
            self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
        self.newlines -= 1
        return self._buffer.readline()


class FastO(IOBase):
    def __init__(self, file):
        self._fd = file.fileno()
        self._buffer = __pypy__.builders.StringBuilder()
        self.write = lambda s: self._buffer.append(s)

    def flush(self):
        os.write(self._fd, self._buffer.build())
        self._buffer = __pypy__.builders.StringBuilder()


def print(*args, **kwargs):
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


sys.stdin, sys.stdout = FastI(sys.stdin), FastO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()