n=input()
lis=map(int,raw_input().split())
su=sum(lis)
x=[' '][:]*su
image=[x[:] for i in range(2002)]
curx=0
cury=1000
maxy=1000
miny=1000
for i in range(n):
    st=lis[i]
    if i%2==1:
        for k in range(st):
            image[cury][curx]='\\'
            cury+=1
            curx+=1
        cury-=1
        maxy=max(maxy,cury)
        
    else:
        for k in range(st):
            image[cury][curx]='/'
            cury-=1
            curx+=1
        cury+=1
        miny=min(miny,cury)
for i in image[miny:maxy+1]:
    print ''.join(i)