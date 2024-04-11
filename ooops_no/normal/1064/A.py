a=[int(i)for i in input().split()]
b=min(a)
a.remove(min(a))
c=min(a)
if b+c>max(a):
    print(0)
else:
    print(max(a)-(b+c)+1)