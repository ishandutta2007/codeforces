import sys
from io import BytesIO
range = xrange
inp = BytesIO(sys.stdin.read())
input = inp.readline
n = int(input())

group = [[] for _ in range(4)]

for _ in range(n):
    a,b = input().split()
    a = int(a,2)
    b = int(b)
    group[a].append(b)

for i in range(4):
    group[i].sort(reverse=True)

k = min(len(group[1]),len(group[2]))

inf = sum(group[1][:k])+sum(group[2][:k])

mixed = group[0]+group[1][k:]+group[2][k:]
mixed.sort(reverse=True)

m = min(len(mixed),len(group[3]))
inf += sum(mixed[:m]) + sum(group[3])

print inf