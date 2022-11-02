x=int(input())
a=[int(i)for i in input().split()]
l=[]
l+=a
l+=[int(i+1)for i in a]
l.sort()
d=len(l)
b=0
while b<d:
    h=l[b]
    for i in range(x):
        if a[i]==h:
            if h%2==0:
                a[i]=a[i]-1
            else:
                a[i]=a[i]+1
    b+=1
print(*a)