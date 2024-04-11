x=map(int,raw_input().split())
s=raw_input()
ans=0
for i in s:
    ans+=x[int(i)-1]
print ans