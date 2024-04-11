a,b=input().split()
a=int(a)
b=int(b)
v=0
l=[]
k=0
s=0
while s<=a+b:
    k+=1
    s+=k
    l.append(k)
del l[-1]
m=[]
for i in range(k-2,-1,-1):
    if a>=l[i]:
        a-=l[i]
        m.append(l[i])
        del l[i]
print(len(m))
print(*m)
print(len(l))
print(*l)