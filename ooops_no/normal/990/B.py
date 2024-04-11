n,k=map(int,input().split())
l=sorted(list(map(int,input().split())))
j=0
for i in l:
    while l[j]<i:
        if i<=k+l[j]:
            n-=1
        j+=1
print(n)