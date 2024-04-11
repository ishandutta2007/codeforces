a,b=map(int,raw_input().split())
x=y=z=0
for i in range(1,7):
    if abs(a-i)>abs(b-i):
        z+=1
    elif abs(a-i)<abs(b-i):
        x+=1
    else:
        y+=1
print x,y,z