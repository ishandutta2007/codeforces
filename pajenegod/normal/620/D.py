import sys
range = xrange
input = raw_input

n = int(input())
A = [float(x) for x in input().split()]

m = int(input())
B = [float(x) for x in input().split()]

summa = sum(A) - sum(B)

AA = [-2*a for a in A]
BB = [-2*b for b in B]

besta = besta0 = abs(summa)
besta1i = -1
besta1j = -1

for i in range(n):
    for j in range(m):
        y = abs(summa + AA[i] - BB[j])
        if besta > y:
            besta = y
            besta1i = i
            besta1j = j

besta1 = besta

AA = [-2*(A[i] + A[j]) for i in range(n) for j in range(n) if i != j]
BB = [-2*(B[i] + B[j]) for i in range(m) for j in range(m) if i != j]

AA.sort()
BB.sort()

N = len(AA)
M = len(BB)

i = 0
j = 0

besta2i = -1
besta2j = -1

while i<N and j<M:
    s = summa + AA[i] - BB[j]
    if abs(s) < besta:
        besta = abs(s)
        besta2i = i
        besta2j = j
    
    if s < 0:
        i += 1
    else:
        j += 1

besta2 = besta

print int(besta)
if besta0 == besta:
    print 0
elif besta1 == besta:
    print 1
    print besta1i + 1, besta1j + 1
else:
    print 2
    aa = - AA[besta2i] // 2
    bb = - BB[besta2j] // 2

    for i1 in range(n):
        for i2 in range(n):
            if i1 != i2 and A[i1] + A[i2] == aa:
                break
        else:
            continue
        break
    
    for j1 in range(m):
        for j2 in range(m):
            if j1 != j2 and B[j1] + B[j2] == bb:
                break
        else:
            continue
        break

    print i1 + 1, j1 + 1
    print i2 + 1, j2 + 1