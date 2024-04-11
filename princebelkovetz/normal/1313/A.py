for _ in range(int(input())):
    a=[int(i) for i in input().split()]
    x=0
    for i in range(3):
        if a[i]>0:
            x+=1
    if a[0]>1 and a[1]>1:
        x+=1
    if a[2]>1 and a[1]>1:
        x+=1
    if a[0]>1 and a[2]>1:
        x+=1
    if a==[2,2,2]:
        x-=2
    elif 2 in a and x==6:
        x-=1
    if min(a)>3:
        x+=1
    print(x)