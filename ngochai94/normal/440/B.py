n=input()
s=map(int,raw_input().split())
ans=0
t=sum(s)/n
cur=0
for i in s:
    ans+=abs(t-i+cur)
    cur=t-i+cur
print ans