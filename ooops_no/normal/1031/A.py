x=list(map(int,input().split()))
v=0
v+=2*(x[0]+x[1])-4
for i in range(1,x[2]):
    v+=2*((x[0]-4)+x[1]-4)-4
    x[0]=x[0]-4
    x[1]=x[1]-4
print(v)