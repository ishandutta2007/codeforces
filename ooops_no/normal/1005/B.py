a,b=input(),input()
x=True
if a>b:
    g=len(b)
    d=1
elif a==b:
    if a==b:
        x=False
        print(0)
    else:
        x=False
        print(len(a)+len(b))
else:
    g=len(a)
    d=2
if x:
    i=1
    while i!=g+1:
        try:
            if a[-i]==b[-i]:
                i+=1
            else:
                i-=1
                if d==2:
                    print(g+len(b)-i*2)
                    break
                else:
                    print(g+len(a)-i*2)
                    break
        except Exception:
            i-=1
            if d==2:
                print(g+len(b)-i*2)
                break
            else:
                print(g+len(a)-i*2)
                break
    else:
        i-=1
        if d==1:
            print(len(a)-i)
        else:
            print(len(b)-i)