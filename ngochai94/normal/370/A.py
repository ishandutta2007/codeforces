r1,c1,r2,c2=map(int,raw_input().split())
a=b=c=0
if r1==r2 or c1==c2:
    a=1
else:
    a=2
if (r1+c1-r2-c2)%2==1:
    b=0
elif abs(r1-r2)==abs(c1-c2):
    b=1
else:
    b=2
c=max(abs(c1-c2),abs(r1-r2))
print a,b,c