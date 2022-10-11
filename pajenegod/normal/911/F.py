import sys
from collections import deque as dq
n = int(input())

ind = 0
inp = [int(x)-1 for line in sys.stdin.readlines() for x in line.split()]

coupl = [[] for _ in range(n)]
for _ in range(n-1):
    a,b = inp[ind],inp[ind+1]
    ind+=2
    coupl[a].append(b)
    coupl[b].append(a)

Q = dq()
found = [False]*n
master = 0
found[master] = True

dia1 = 0
Q.append(master)
while Q:
    node = Q.popleft()
    dia1 = node
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = True
            Q.append(nei)


dia2 = 0
Q.append((dia1,0))
dist1 = [0]*n
found = [False]*n
found[dia1] = True
while Q:
    node,d = Q.popleft()
    dia2 = node
    dist1[node]=d
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = True
            Q.append((nei,d+1))

Q = []
Q.append((dia2,0))
dist2 = [0]*n
found = [False]*n
found[dia2] = True
while Q:
    node,d = Q.pop()
    dist2[node]=d
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = True
            Q.append((nei,d+1))

neigs = [0]*n

leaves = []
for i in range(n):
    if i != dia1 and i != dia2 and len(coupl[i])==1:
        leaves.append(i)
    neigs[i]=len(coupl[i])
points = 0
lista = []

while leaves:
    node = leaves.pop()
    if dist1[node]<dist2[node]:
        lista.append((dia2,node,node))
        points += dist2[node]
    else:
        lista.append((dia1,node,node))
        points += dist1[node]
    for nei in coupl[node]:
        neigs[nei]-=1
        if neigs[nei]==1:
            leaves.append(nei)
leaves.append(dia2)
while leaves:
    node = leaves.pop()
    lista.append((dia1,node,node))
    points += dist1[node]
    for nei in coupl[node]:
        neigs[nei]-=1
        if neigs[nei]==1:
            leaves.append(nei)
print(points)
for l in lista:
    a,b,c = l
    print(a+1,b+1,c+1)