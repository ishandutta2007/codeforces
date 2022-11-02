n,d=map(int,input().split())
x=int(input())
for i in range(x):
    x,y=map(int,input().split())
    if y-x>=-d and y-x<=d and x+y<=2*n-d and x+y>=d:
        print('YES')
    else:
        print('NO')