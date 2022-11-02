x,m=map(int,input().split())
l=list(map(int,input().split()))
l1=[0]+[int(0)for i in range(x)]
for i in l:
    l1[i]+=1
print(min(l1[1:]))