a,k=map(int,raw_input().split())
lis=[]
for i in str(a):
    lis.append(i)
curind=0
n=len(lis)
while k!=0 and curind!=n-1:
    car=max(lis[curind:min(n,curind+k+1)])
    if car!=lis[curind]:
        x=lis[curind:].index(car)
        k-=x
        lis=lis[:curind]+[car]+lis[curind:x+curind]+lis[x+curind+1:]
    curind+=1
print int(''.join(lis))