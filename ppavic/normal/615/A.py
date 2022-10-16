x,y=map(int,input().split())
iz=set()
for t in range(x):
    t=list(map(int,input().split()))
    for p in range(1,t[0]+1):iz.add(t[p])
if len(iz)!=y:
    print('NO')
else:
    print('YES')