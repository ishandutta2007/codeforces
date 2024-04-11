n=int(input())
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
c=sorted(a[i]-b[i] for i in range (n))
cou=0
l=0
r=n-1
while l < r:
    if c[l]+c[r]>0:
        cou+=r-l
        r-=1
    else:
        l+=1
print(cou)