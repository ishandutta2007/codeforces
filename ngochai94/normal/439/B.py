n,x=map(int,raw_input().split())
s=map(int,raw_input().split())
s.sort()
ans=0
for i in s:
    ans+=i*x
    x=max(1,x-1)
print ans