t,k=map(int,raw_input().split())
m=1000000007 
lis=[1]*k
s=[0]
for i in range(k,100001):
    lis.append((lis[i-1]+lis[i-k])%m)
for i in lis:
    s.append((i+s[-1])%m)
for _ in range(t):
    a,b=map(int,raw_input().split())
    print (s[b+1]-s[a])%m