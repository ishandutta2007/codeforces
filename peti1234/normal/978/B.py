n=int(input())
s=input()
ans=0
for i in range(2, n, 1):
    if s[i-2]=='x' and s[i-1]=='x' and s[i]=='x':
        ans=ans+1
print(ans)