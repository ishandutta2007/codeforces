a,b=map(int,input().split()) 
if b//a==2:
    b=b%a
    print(a-b)
else:
    print(0)