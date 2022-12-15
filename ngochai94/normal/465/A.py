n=input()
s=raw_input()
ans=0
for i in s:
    if i=='0':
        break
    ans+=1
print min(n,ans+1)