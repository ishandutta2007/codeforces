import sys
from collections import defaultdict as di
color = input()
n = len(color)

lnei = [-1]*n
rnei = [-1]*n
to_be_deleted = []
deleted = [False]*n
iters = 0

for i in range(n):
    if i-1>=0:
        lnei[i]=i-1
        if color[i]!=color[i-1]:
            to_be_deleted.append(i)
    if i+1<n:
        rnei[i]=i+1
        if color[i]!=color[i+1]:
            to_be_deleted.append(i)

if len(to_be_deleted)==0:
    print(0)
    sys.exit()

while True:
    was_deleted = False

    pot_sui = []
    for node in to_be_deleted:
        if deleted[node]:
            continue
        was_deleted=True
        deleted[node]=True
        
        if rnei[node]!=-1:
            lnei[rnei[node]]=lnei[node]
            pot_sui.append(rnei[node])

        if lnei[node]!=-1:
            rnei[lnei[node]]=rnei[node]
            pot_sui.append(lnei[node])
    
    
    to_be_deleted=[]
    for node in pot_sui:
        if deleted[node]:
            continue
        if lnei[node]!=-1 and color[node]!=color[lnei[node]]:
            to_be_deleted.append(node)
        elif rnei[node]!=-1 and color[node]!=color[rnei[node]]:
            to_be_deleted.append(node)
    if not was_deleted:
        break
    iters += 1

print(iters)