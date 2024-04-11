x=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
cnt=0
for i in l:
    if i>a:
        cnt+=b*(i//(a+b))
        i-=i//(a+b)*(a+b)
    if i-b>0 and i>a and i-b<=a:
        cnt+=b
print(cnt)