n=input()
s=map(int,raw_input().split())
each=sum(s)/3
su=[s[0]]
for i in range(1,n):
    su.append(su[-1]+s[i])
ans=0
for1=0
for2=0
for i in su[:-2]:
    if i==each:
        for1+=1
for i in su[1:-1]:
    if i==2*each:
        for2+=1
if su[0]==each:
    ans+=for2
for i in su[1:-1]:
    if i==2*each:
        for2-=1
    if i==each:
        ans+=for2
if sum(s)%3!=0:
    ans=0
print ans