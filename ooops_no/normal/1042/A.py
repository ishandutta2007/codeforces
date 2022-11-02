kol_vo=int(input())
was=int(input())
maximum=0
g=0
f=[]
for _ in range(kol_vo):
    h=int(input())
    if h>maximum:
        maximum=h
    g+=h
    f+=[h]
h=[]
if (was+g)%kol_vo==0:
    o=(was+g)//kol_vo
else:
    o=(was+g)//kol_vo+1
if max(f)>o:
    h.append(max(f))
else:
    h.append(o)
h.append(maximum+was)
print(*h)