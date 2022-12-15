def sumdi(s):
    ans=0
    for i in str(s):
        ans+=int(i)
    return ans
a,b,c=map(int,raw_input().split())
ans=[]
for i in range(1,82):
    k=b*(i**a)+c
    if k>0 and k<10**9:
        if sumdi(k)==i:
            ans.append(k)
ans.sort()
print len(ans)
for i in ans:
    print i,