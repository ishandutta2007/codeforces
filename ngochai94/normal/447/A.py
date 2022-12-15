p,n=map(int,raw_input().split())
lis=[0]*p
done=False
for i in range(1,n+1):
    k=input()%p
    if lis[k]==0:
        lis[k]=1
    else:
        done=True
        print i
        break
if not done:
    print -1