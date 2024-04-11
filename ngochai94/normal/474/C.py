def square(x1,y1,x2,y2,x3,y3,x4,y4):
    if len(set([(x1,y1),(x2,y2),(x3,y3),(x4,y4)]))!=4 :
        return False
    cenx=float(x1+x2+x3+x4)/4
    ceny=float(y1+y2+y3+y4)/4
    if cenx*2==x1+x2:
        if ceny*2==y1+y2:
            if (x1-cenx)*(x3-cenx)+(y1-ceny)*(y3-ceny)==0:
                if abs(x1-cenx)==abs(y3-ceny) and abs(x3-cenx)==abs(y1-ceny):
                    return True
    if cenx*2==x1+x3:
        if ceny*2==y1+y3:
            if (x1-cenx)*(x2-cenx)+(y1-ceny)*(y2-ceny)==0:
                if abs(x1-cenx)==abs(y2-ceny) and abs(x2-cenx)==abs(y1-ceny):
                    return True
    if cenx*2==x1+x4:
        if ceny*2==y1+y4:
            if (x1-cenx)*(x3-cenx)+(y1-ceny)*(y3-ceny)==0:
                if abs(x1-cenx)==abs(y3-ceny) and abs(x3-cenx)==abs(y1-ceny):
                    return True
    return False
def gen(x,y,a,b,i):
    if i==0:
        return (x,y)
    if i==1:
        return (a-(y-b),b+x-a)
    if i==2:
        return (a-(x-a),b-(y-b))
    if i==3:
        return (a+y-b,b-(x-a))
for _ in range(input()):
    x1,y1,a1,b1=map(int,raw_input().split())
    x2,y2,a2,b2=map(int,raw_input().split())
    x3,y3,a3,b3=map(int,raw_input().split())
    x4,y4,a4,b4=map(int,raw_input().split())
    ans=100
    for r1 in range(4):
        for r2 in range(4):
            for r3 in range(4):
                for r4 in range(4):
                    xv1,yv1=gen(x1,y1,a1,b1,r1)
                    xv2,yv2=gen(x2,y2,a2,b2,r2)
                    xv3,yv3=gen(x3,y3,a3,b3,r3)
                    xv4,yv4=gen(x4,y4,a4,b4,r4)
                    if square(xv1,yv1,xv2,yv2,xv3,yv3,xv4,yv4):
                        ans=min(ans,r1+r2+r3+r4)
    if ans==100:
        print -1
    else:
        print ans