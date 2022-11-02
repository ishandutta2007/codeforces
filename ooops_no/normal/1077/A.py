x=int(input())
for _ in range(x):
    a,b,c=map(int,input().split())
    if c%2==0:
        print((a-b)*(c//2))
    else:
        print((a-b)*(c//2)+a)