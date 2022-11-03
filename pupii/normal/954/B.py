n=int(input());s=input()
ans=n
for i in range(1,n//2+1):
    if s[0:i]==s[i:i*2]:
        ans=min(ans,n-i+1)
print(ans)