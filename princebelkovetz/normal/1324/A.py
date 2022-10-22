for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    if a[0]%2==0:
        f=False
    else:
        f = True
    xx=False
    for i in range(1,n):
        if (a[i]%2==0 and f) or (a[i]%2==1 and not f):
            xx= True
            print('NO')
            break
    if not xx:
        print('YES')