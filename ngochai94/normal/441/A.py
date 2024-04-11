n,v=map(int,raw_input().split())
ans=[]
for i in range(1,n+1):
    s=map(int,raw_input().split())
    if v>min(s[1:]):
        ans.append(i)
print len(ans)
for i in ans:
    print i,