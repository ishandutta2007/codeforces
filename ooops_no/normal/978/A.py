x=int(input())
a=[int(i)for i in input().split()]
l=[]
l+=a
d=0
for i in a:
    if l.count(i)>1:
        l.remove(i)
        d+=1
print(len(l))
print(*l)