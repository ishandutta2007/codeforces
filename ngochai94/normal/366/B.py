n,k=map(int,raw_input().split())
s=map(int,raw_input().split())
ans=10**9
x=1
for i in range(k):
    com=sum(s[i::k])
    if com<ans:
        ans=com
        x=i+1
print x