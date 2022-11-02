x=[int(i)for i in input().split()]
l=[int(i)for i in range(1,x[1]+1)]
for i in range(x[0]):
    a=[int(i)for i in input().split()]
    for j in range(a[0],a[1]+1):
        if j in l:
            l.remove(j)
print(len(l))
print(*l)