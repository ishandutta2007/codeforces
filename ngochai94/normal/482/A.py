n,k=map(int,raw_input().split())
c=k+2
for i in range((c-1)/2):
    print i+1, c-i-1,
if c%2==0:
    print c/2,
for j in range(c,n+1):
    print j,