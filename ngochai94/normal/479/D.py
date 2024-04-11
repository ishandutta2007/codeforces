n,l,x,y=map(int,raw_input().split())
ori=map(int,raw_input().split())
boy=[]
girl=[]
for i in ori:
    if i-x>=0:
        girl.append(i-x)
    if i+x<=l:
        girl.append(i+x)
    if i-y>=0:
        boy.append(i-y)
    if i+y<=l:
        boy.append(i+y)
girl.sort()
boy.sort()
bh=gh=False
bg=False
i=0
for k in girl:
    while ori[i]<k and i<n-1:
        i+=1
    if ori[i]==k:
        gh=True
i=0
for k in boy:
    while ori[i]<k and i<n-1:
        i+=1
    if ori[i]==k:
        bh=True
if gh and bh:
    print 0
elif gh:
    print 1
    print y
elif bh:
    print 1
    print x
else:
    i=0
    n=len(girl)
    for k in boy:
        while girl[i]<k and i<n-1:
            i+=1
        if girl[i]==k:
            bg=True
            break
    if bg:
        print 1
        print k
    else:
        print 2
        print x,y