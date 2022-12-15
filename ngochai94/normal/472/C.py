n=input()
name=[]
for i in range(n):
    name.append(raw_input().split())
rank=map(int,raw_input().split())
for i in range(n):
    rank[i]-=1
flag=True
cur=min(name[rank[0]])
for i in range(1,n):
    a,b=name[rank[i]]
    if a>b:
        a,b=b,a
    if a>cur:
        cur=a
    elif b>cur:
        cur=b
    else:
        flag=False
        break
if flag:
    print 'YES'
else:
    print 'NO'