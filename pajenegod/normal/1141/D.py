from __future__ import print_function
import os,sys,atexit

if sys.version_info[0] < 3:
    range = xrange
    from cStringIO import StringIO as BytesIO
    sys.stdout = BytesIO()
else:
    from io import BytesIO
    sys.stdout = BytesIO()
    _write = sys.stdout.write
    sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
L = input()
R = input()

Lcount = [[] for _ in range(200)]
Rcount = [[] for _ in range(200)]

for i,l in enumerate(L):
    Lcount[l].append(i)
for i,r in enumerate(R):
    Rcount[r].append(i)

out = []
for c in range(ord('a'),ord('z')+1):
    Ltmp = Lcount[c]
    Rtmp = Rcount[c]
    while Ltmp and Rtmp:
        i = Ltmp.pop()
        j = Rtmp.pop()
        out.append((i+1,j+1))

Ltmp = Lcount[ord('?')]
for c in range(ord('a'),ord('z')+1):
    Rtmp = Rcount[c]
    while Ltmp and Rtmp:
        i = Ltmp.pop()
        j = Rtmp.pop()
        out.append((i+1,j+1))

Rtmp = Rcount[ord('?')]
for c in range(ord('a'),ord('z')+1):
    Ltmp = Lcount[c]
    while Ltmp and Rtmp:
        i = Ltmp.pop()
        j = Rtmp.pop()
        out.append((i+1,j+1))

Ltmp = Lcount[ord('?')]
Rtmp = Rcount[ord('?')]

while Ltmp and Rtmp:
    i = Ltmp.pop()
    j = Rtmp.pop()
    out.append((i+1,j+1))
print(len(out))
for x,y in out:
    sys.stdout.write(str(x))
    sys.stdout.write(" ")
    sys.stdout.write(str(y))
    sys.stdout.write("\n")