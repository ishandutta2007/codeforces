import sys

#file=open("data.in")
#file=sys.stdin



a=sys.stdin.readline().split()
x=int(a[0])
y=int(a[1])
z=int(a[2])
k=int(a[3])

qx=x-1
qy=y-1
qz=z-1

if (k<(x+y+z-3)):
    for i in xrange(x+y+z-3-k):
        a=qx
        b=qy
        c=qz
        #print(a,' ',b,' ',c)
        if (a<=c and b<=c):
            qz=qz-1
        elif (a<=b and c<=b):
            qy=qy-1
        elif (c<=a and b<=a):
            qx=qx-1

    
    q=(qx+1)*(qy+1)*(qz+1)
else:
    q=x*y*z
print(q)