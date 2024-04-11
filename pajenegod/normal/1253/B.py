import sys
range = xrange
input = raw_input

def fail():
    print -1
    sys.exit()

n = int(input())
A = [int(x) for x in input().split()]

A = [a - (a > 0) for a in A]

days = []
c = 0

Aset = set()
used = set()
for i in range(n):
    c += 1
    a = A[i]
    if a >= 0:
        if a in Aset or a in used:
            fail()
        Aset.add(a)
        used.add(a)
    else:
        a = ~a
        if a not in Aset:
            fail()
        Aset.remove(a)

        if len(Aset) == 0:
            days.append(c)
            c = 0
            used = set()
if len(Aset) > 0:
    fail()

print len(days)
print ' '.join(str(x) for x in days)