m,n=map(int,raw_input().split())
ans=0.0
for i in range(m,0,-1):
    ans+=float(i)*(float(i)/m)**n*(1-(float(i-1)/i)**n)
print ans