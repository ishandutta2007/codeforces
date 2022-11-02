c,a,b=input().split()
c=int(c)
level=0
while c!=1:
    level+=1
    c//=2
a=int(a)-1
b=int(b)-1
roundik=0
while a!=b:
    roundik+=1
    a//=2
    b//=2
if roundik==level:
    print("Final!")
else:
    print(roundik)