hi=int(input())
a=[int(i)for i in input()]
x=False
g=0
if len(a)==sum(a):
    x=True
    for i in a:
        if i==1:
            pass
        else:
            x=False
            break
    if x:
        print("YES")
    else:
        print("NO")
else:
    for k in range(2,len(a)+1):
        if sum(a)%k==0:
            l=0
            x=True
            for i in a:
                if l+i==sum(a)//k:
                    l=0
                elif l>sum(a)//k:
                    x=False
                    break
                else:
                    l+=i
            if l+i>sum(a)//k:
                x=False
            if x:
                break
    if x:
        print("YES")
    else:
        print("NO")