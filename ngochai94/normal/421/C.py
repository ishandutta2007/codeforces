n,m=map(int,raw_input().split())
log=[]
for _ in range(m):
    i=raw_input().split()
    log.append((i[0],int(i[1])))
newlog=[0]*(n+1)
minus=False
last=0
bef=0
for i in log:
    if newlog[i[1]]==0:
        newlog[i[1]]=1
        if i[0]=='-':
            bef+=1
            minus=True
            last=i[1]
ans=[]
for i in range(1,n+1):
    if newlog[i]==0:
        ans.append(i)
if minus:
    lastin=1
    choose=True
    for i in log:
        if i[1]==last:
            lastin=1-lastin
        if i[0]=='-':
            bef-=1
        else:
            bef+=1
        if lastin==0 and bef>0:
            choose=False
            break
    if choose:
        ans.append(last)
else:
    eva=log[0][1]
    cur=0
    evain=0
    choose=True
    for i in log:
        if i[1]==eva:
            evain=1-evain
        if i[0]=='-':
            cur-=1
        else:
            cur+=1
        if evain==0 and cur>0:
            choose=False
            break
    if choose:
        ans.append(eva)
ans.sort()
print len(ans)
for i in ans:
    print i,