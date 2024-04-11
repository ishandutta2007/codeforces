r = range
F,I,T=map(int,input().split())
G=[0]*11
for i in r(F):
    G[i]=input()
ans=0
for j in r(I):
    c=0
    for i in r(F):
        if G[i][j]=='Y':
            c+=1
    if c>=T:
        ans+=1
print(ans)
#kitten