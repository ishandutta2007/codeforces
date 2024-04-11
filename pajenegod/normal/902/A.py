import sys
n,m=[int(x) for x in input().split()]
points = []
for _ in range(n):
    a,b = [int(x) for x in input().split()]
    points.append((b,a))

reach = m
points.sort(reverse=True)
for b,a in points:
    if a<=reach<=b:
        reach=min(a,reach)

if reach==0:
    print('YES')
else:
    print('NO')