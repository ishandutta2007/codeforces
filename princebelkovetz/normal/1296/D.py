n,a,b,k=map(int,input().split())
c=[int(i)for i in input().split()]
d=[]
cou=0
for i in range(n):
    if c[i]%(a+b)==0:
        if b>a:
            d.append(b//a+1)
        else:
            d.append(1)
    elif c[i]%(a+b)<=a:
        cou+=1
    else:
        x=c[i]%(a+b)
        if x%a==0:
            d.append(x//a-1)
        else:
            d.append(x//a)
d=sorted(d)
for i in range(len(d)):
    if k>=d[i]:
        k-=d[i]
        cou+=1
    else:
        break
print(cou)