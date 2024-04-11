x=raw_input().split()
n=int(x[0])
t=int(x[1])
c=int(x[2])
x=raw_input().split()
for i in range(n):
    x[i]=int(x[i])
cur=0
ans=0
for i in x:
    if i>t:
        if cur>=c:
            ans+=cur+1-c
        cur=0
    else:
        cur+=1
if cur>=c:
    ans+=cur+1-c
print ans