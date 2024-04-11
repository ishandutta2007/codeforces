import atexit
import os
import sys
import __pypy__


class Fastio:
  def __init__(self):
    self.ibuf = bytes()
    self.pil = 0
    self.pir = 0
    self.sb = __pypy__.builders.StringBuilder()

  def load(self):
    self.ibuf = self.ibuf[self.pil:]
    self.ibuf += os.read(0, 131072)
    self.pil = 0
    self.pir = len(self.ibuf)

  def flush(self):
    os.write(1, self.sb.build().encode())

  def fastin(self):
    if self.pir - self.pil < 32:
      self.load()
    minus = 0
    x = 0
    while self.ibuf[self.pil] < 45:
      self.pil += 1
    if self.ibuf[self.pil] == 45:
      minus = 1
      self.pil += 1
    while self.ibuf[self.pil] >= 48:
      x = x * 10 + (self.ibuf[self.pil] & 15)
      self.pil += 1
    if minus:
      x = -x
    return x

  def fastout(self, x):
    self.sb.append(str(x))

  def fastoutln(self, x):
    self.sb.append(str(x))
    self.sb.append('\n')


fastio = Fastio()
rd = fastio.fastin
wt = fastio.fastout
wtn = fastio.fastoutln
atexit.register(fastio.flush)
sys.stdin, sys.stdout = None, None

N = rd()
a = [0] * N
for i in range(N):
  a[i] = rd()
for i in range(N - 1, 0, -1):
  a[i] -= a[i - 1]
p = 0
for i in range(1, N):
  p += max(0, a[i])
wtn((a[0] + p + 1) // 2)
Q = rd()
for _ in range(Q):
  l, r, x = rd(), rd(), rd()
  l -= 1
  if l != 0:
    p -= max(a[l], 0)
  a[l] += x
  if l != 0:
    p += max(a[l], 0)
  if r != N:
    p -= max(a[r], 0)
    a[r] -= x
    p += max(a[r], 0)
  wtn((a[0] + p + 1) // 2)