t=int(input())
cou=[]
def lab(x1,y1,x,y):
    return abs(x-x1)+abs(y1-y)
def xadder(x0,y0,gv):
    x1=a[2*gv]
    y1=a[2*gv+1]
    x1=x1-x0
    y1=y1-y0
    if x1<0 or y1<0:
        return 'NO'
    else:
        return 'R'*x1+'U'*y1
for i in range(t):
    n=int(input())
    ft=True
    a=[]
    b=[]
    ff=''
    x1=0
    y1=0
    c=[]
    for j in range(n):
        x,y=map(int,input().split())
        a.append(x)
        a.append(y)
        b.append(lab(x,y,x1,y1))
    for j in range(n):
        gj=min(b)
        gv=b.index(gj)

        if xadder(x1,y1,gv)=='NO':
            cou.append('NO')
            ft=False
            break
        else:
            ff+=(xadder(x1,y1,gv))
        c.append(gv)
        x1 = a[2 * gv]
        y1 = a[2 * gv + 1]
        b=[]
        for k in range(n):
            b.append(lab(x1, y1, a[2 * k ], a[2 * k + 1]))
        for i in range(len(c)):
            b[c[i]]=99999999
    if ft:
        cou.append('YES'+'\n'+ff)
for i in range(len(cou)):
    print(cou[i])