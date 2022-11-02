x=int(input())
a=[int(i)for i in input().split()]
c=0
h=0
b=0
l=[]
for i in a:
    if c+1==i:
        b+=1
        c=i
    else:
        h+=1
        l+=[b]
        b=0
        c=1
        b+=1
h+=1
if b!=0:
    l+=[b]
print(h)
print(*l)