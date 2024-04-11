#!/usr/bin/env python
# testing NoticeMeSenpaiT_T code
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase

py2 = round(.5)
if py2:
  from __builtin__ import xrange as range
  from future_builtins import ascii, filter, hex, map, oct, zip

BUFSIZE = 8192
class FastIO(IOBase):
  newlines = 0

  def __init__(self, file):
    self._buffer = BytesIO()
    self._fd = file.fileno()
    self._writable = "x" in file.mode or "r" not in file.mode
    if self._writable:
        self.write = self._buffer.write if py2 else \
            (lambda s: self._buffer.write(s.encode()))

  def readline(self):
    while self.newlines == 0:
      b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
      self.newlines = b.count(b"\n") + (not b)
      ptr = self._buffer.tell()
      self._buffer.seek(0, 2), self._buffer.write(b), self._buffer.seek(ptr)
    self.newlines -= 1
    s = self._buffer.readline()
    return s if py2 else s.decode()

  def flush(self):
    if self._writable:
      os.write(self._fd, self._buffer.getvalue())
      self._buffer.truncate(0), self._buffer.seek(0)


sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

reads = lambda: [int(x) for x in input().split()]
read = lambda: int(input())
s = input()
a = s.count('a')
print(min(len(s), a * 2 - 1))