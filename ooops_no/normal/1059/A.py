x=[int(i)for i in input().split()]
l=0
h=0
for i in range(x[0]):
    a=[int(i)for i in input().split()]
    if l<a[0]:
        h+=(a[0]-l)//x[2]
    l=a[0]+a[1]
h+=(x[1]-l)//x[2]
print(h)