n,x=map(int,raw_input().split())
type0=[]
type1=[]
for _ in range(n):
    t,h,m=map(int,raw_input().split())
    if t==0:
        type0.append((h,m))
    else:
        type1.append((h,m))
type0.sort()
type1.sort()
cur0=[]
cur1=[]
ans0=0
ans1=0
mark=0
type01=type0[:]
type11=type1[:]
x1=x
while True:
    while type0!=[]:
        if type0[0][0]<=x:
            cur0.append(type0[0])
            type0=type0[1:]
        else:
            break
    while type1!=[]:
        if type1[0][0]<=x:
            cur1.append(type1[0])
            type1=type1[1:]
        else:
            break
    if mark==0:
        h=0
        m=0
        if cur0==[]:
            break
        for i in cur0:
            if m<i[1]:
                m=i[1]
                h=i[0]
        cur0.remove((h,m))
        x+=m
    else:
        h=0
        m=0
        if cur1==[]:
            break
        for i in cur1:
            if m<i[1]:
                m=i[1]
                h=i[0]
        cur1.remove((h,m))
        x+=m
    ans0+=1
    mark=1-mark
mark=1
cur0=[]
cur1=[]
type0=type01[:]
type1=type11[:]
x=x1
while True:
    while type0!=[]:
        if type0[0][0]<=x:
            cur0.append(type0[0])
            type0=type0[1:]
        else:
            break
    while type1!=[]:
        if type1[0][0]<=x:
            cur1.append(type1[0])
            type1=type1[1:]
        else:
            break
    if mark==0:
        h=0
        m=0
        if cur0==[]:
            break
        for i in cur0:
            if m<i[1]:
                m=i[1]
                h=i[0]
        cur0.remove((h,m))
        x+=m
    else:
        h=0
        m=0
        if cur1==[]:
            break
        for i in cur1:
            if m<i[1]:
                m=i[1]
                h=i[0]
        cur1.remove((h,m))
        x+=m
    ans1+=1
    mark=1-mark
print max(ans0,ans1)