a,b,c=map(int,raw_input().split())
x,y,z=map(int,raw_input().split())
n=input()
if (a+b+c+4)/5+(x+y+z+9)/10<=n:
    print 'YES'
else:
    print 'NO'