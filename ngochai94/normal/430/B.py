def mod(li):
    lis=li[:]
    if len(lis)<3:
        return lis
    else:
        for i in range(len(lis)-2):
            if lis[i]==lis[i+1]==lis[i+2]:
                a=lis[i]
                while lis[i]==a:
                    lis=lis[:i]+lis[i+1:]
                    if len(lis)==i:
                        break
                break
        if li==lis:
            return li
        else:
            return mod(lis)
t=map(int,raw_input().split())
n=t[0]
k=t[1]
x=t[2]
lis=map(int,raw_input().split())
ans=n
for i in range(2,n):
    li=lis[:]
    li.insert(i,x)
    ans=min(ans,len(mod(li)))
print n-ans