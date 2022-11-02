x=int(input())
for i in range(x):
    l,r=map(int,input().split())
    string=''
    cnt=1
    while l!=0:
        need=l//r
        l-=need
        r-=1
        string+=chr(cnt+96)*need
        cnt+=1
    print(string)