x=[int(i)for i in input().split()]
l=0
if x[0]-1<x[1]:
    min=0
else:
    min=x[0]-x[1]*2
    if min<0:
        min=0
if x[1]==0:
    max=x[0]
else:
    for i in range(x[0]):
        l+=i
        if l==x[1]:
            max=x[0]-(i+1)
            break
        elif l>x[1]:
            max=x[0]-(i+1)
            break
print(min,max)