t=int(input())
def an(x):
    if x=='S':
        return 'N'
    if x=='N':
        return 'S'
    if x=='W':
        return 'E'
    if x=='E':
        return 'W'
def mov(x,y):
    if y=='S':
        return (x[0]+1,x[1])
    if y=='N':
        return (x[0]-1,x[1])
    if y=='W':
        return (x[0],x[1]+1)
    if y=='E':
        return (x[0],x[1]-1)
while t>0:
    t-=1
    li={}
    s=input()
    at=(0,0)
    ans=0
    for i in s:
        nx=mov(at,i)
        if li.get((at,i),False):
            ans+=1
        else:
            ans+=5
            li[(at,i)]=True
            li[(nx,an(i))]=True
        at=nx
    print(ans)