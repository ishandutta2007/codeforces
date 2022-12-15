n,m=map(int,raw_input().split())
s=map(int,raw_input().split())
for i in range(n):
    s[i]=(s[i]+m-1)/m
k=max(s)
for i in range(n-1,-1,-1):
    if s[i]==k:
        print i+1
        break