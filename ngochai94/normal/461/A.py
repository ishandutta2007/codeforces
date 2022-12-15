n=input()
s=map(int,raw_input().split())
s.sort()
if n==1:
    print s[0]
elif n==2:
    print 2*(s[0]+s[1])
else:
    ans=0
    for i in range(n-1):
        ans+=(i+2)*s[i]
    ans+=n*s[-1]
    print ans