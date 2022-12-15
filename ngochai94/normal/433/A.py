n=input()
x=map(int,raw_input().split())
a=x.count(100)
b=x.count(200)
if a%2==1 or (b%2==1 and a==0):
    print 'NO'
else:
    print 'YES'