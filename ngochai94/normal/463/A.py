n,s=map(int,raw_input().split())
ans=0
s*=100
can=0
for _ in range(n):
    a,b=map(int,raw_input().split())
    p=100*a+b
    if s>=p:
        can=1
        ans=max(ans,(s-p)%100)
if can==0:
    print -1
else:
    print ans