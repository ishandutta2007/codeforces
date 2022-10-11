import sys
range = xrange
input = raw_input
n,m,d = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

free = (d - 1) * (m + 1)

if sum(C) + free < n:
    print 'NO'
    sys.exit()

extra = n - sum(C)

place = []
x = 1
for i in range(m):
    t = min(d-1,extra)
    x += t
    extra -= t

    place.append(x)
    x += C[i]


pos = [0]*n
for i in range(m):
    for j in range(place[i], place[i] + C[i]):
        pos[j - 1] = i + 1

print 'YES'
print ' '.join(str(x) for x in pos)