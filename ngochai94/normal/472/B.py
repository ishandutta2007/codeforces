n,k=map(int,raw_input().split())
s=map(int,raw_input().split())
s.sort()
ans=s[-1]-1
fl=1
while True:
    t=len(s)
    if t==0:
        break
    ans+=2*(1+(t-1)/k)-1
    fl+=1
    for i in range(t):
        if s[i]>fl:
            break
    if s[-1]<=fl:
        s=[]
    else:
        s=s[i:]
print ans