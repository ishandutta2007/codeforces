x=int(input())
for i in range(x):
    a,b,c=map(int,input().split())
    if a>c:
        print(c)
    else:
        print((b//c+1)*c)