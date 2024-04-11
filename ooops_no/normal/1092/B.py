x=int(input())
l=list(map(int,input().split()))
l.sort()
cnt=0
for i in range(0,x-1,2):
    if l[i]!=l[i+1]:
        cnt+=l[i+1]-l[i]
print(cnt)