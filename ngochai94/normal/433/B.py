n=input()
x=map(int,raw_input().split())
y=sorted(x)
ax=[0]
ay=[0]
for i in x:
    ax.append(ax[-1]+i)
for i in y:
    ay.append(ay[-1]+i)
m=input()
lis=[]
for i in range(m):
    x=map(int,raw_input().split())
    if x[0]==1:
        lis.append(ax[x[2]]-ax[x[1]-1])
    else:
        lis.append(ay[x[2]]-ay[x[1]-1])
for i in lis:
    print i