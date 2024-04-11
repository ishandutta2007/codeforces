n=input()
s=map(int,raw_input().split())
c=0
ans=0
for i in range(1,n):
    if s[i]<s[i-1]:
        c+=1
        ans=n-i
if (c==1 and s[0]>=s[-1]) or c==0:
    print ans
else:
    print -1