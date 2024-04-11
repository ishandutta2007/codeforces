x,y=map(int,raw_input().split())
n=input()%6
t=1000000007 
if n==0:
    print (x-y)%t
if n==1:
    print x%t
if n==2:
    print y%t
if n==3:
    print (y-x)%t
if n==4:
    print (-x)%t
if n==5:
    print (-y)%t