t=int(input())
cou=[]
for i in range(t):
    a,b,c,n=map(int,input().split())
    x=max(a,b,c)
    if c==x:
        y=c+c-a-b
        if (n-y)%3==0 and n-y>=0:
            cou.append('YES')
        else:
            cou.append('NO')
    elif b==x:
        y=b+b-a-c
        if (n-y)%3==0 and n-y>=0:
            cou.append('YES')
        else:
            cou.append('NO')
    else:
        y=a+a-c-b
        if (n-y)%3==0 and n-y>=0:
            cou.append('YES')
        else:
            cou.append('NO')


for i in range(t):
    print(cou[i])