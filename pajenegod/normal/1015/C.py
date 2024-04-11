import sys
input = sys.stdin.readline
range = xrange

n,m = [int(x) for x in input().split()]
C = [(int(a)-int(b),int(a)) for _ in range(n) for a,b in [input().split()]]

C.sort(reverse=True)

summa = 0
for c,a in C:
    summa += a
comp = 0
for c,a in C:
    if summa<=m:
        break
    summa -= c
    comp += 1

if summa>m:
    print -1
else:
    print comp