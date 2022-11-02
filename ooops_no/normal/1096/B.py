x=int(input())
s=input()
last=s[0]
cnt=0
cntb=1
for i in s:
    if last!=i:
        break
    else:
        cnt+=1
cnt1=0
for i in s[::-1]:
    if s[-1]!=i:
        break
    else:
        cnt1+=1
if s[-1]==s[0]:
    print((cnt+1)*(cnt1+1)%998244353)
else:
    print((cnt+cnt1+1)%998244353)