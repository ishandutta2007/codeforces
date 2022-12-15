n,t=map(int,raw_input().split())
lis=map(int,raw_input().split())
por=[0]*n
for i in range(1,n):
    por[i]=i+lis[i-1]
cur=1
while cur!=n and cur!=t:
    cur=por[cur]
if cur==t:
    print 'YES'
else:
    print 'NO'