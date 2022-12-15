n,l,x,y=map(int,raw_input().split())
ori=map(int,raw_input().split())
boy=[]
girl=[]
for i in ori:
    if i+y<=l:
        boy.append(i+y)
    if 0<=i-y:
        boy.append(i-y)
    if i+x<=l:
        girl.append(i+x)
    if i-x>=0:
        girl.append(i-x)
tem=0
boy.sort()
girl.sort()
bh=False
gh=False
for i in boy:
    while i>ori[tem] and tem<n-1:
        tem+=1
    if i==ori[tem]:
        bh=True
        break
tem=0
for j in girl:
    while j>ori[tem] and tem<n-1:
        tem+=1
    if j==ori[tem]:
        gh=True
        break
if bh and gh:
    print 0
elif bh:
    print 1
    print x
elif gh:
    print 1
    print y
else:
    bg=False
    tem=0
    for i in boy:
        while i>girl[tem] and tem<len(girl)-1:
            tem+=1
        if i==girl[tem]:
            bg=True
            break
    if bg:
        print 1
        print i
    else:
        print 2
        print x,y