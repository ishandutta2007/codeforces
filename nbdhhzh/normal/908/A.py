a=input()
ans=0
for i in range(len(a)):
    if (a[i]=='a')|(a[i]=='e')|(a[i]=='i')|(a[i]=='o')|(a[i]=='u'):
        ans=ans+1
    if (a[i]>='0')&(a[i]<='9')&(ord(a[i])%2==1):
        ans=ans+1
print(ans)