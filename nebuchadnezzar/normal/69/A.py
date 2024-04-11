import sys

#file=open("data.in")
#file=sys.stdin

n=int(sys.stdin.readline())

x=[0]*n
y=[0]*n
z=[0]*n
for j in range(n):
    a = sys.stdin.readline().split()
    x[j]=int(a[0])
    y[j]=int(a[1])
    z[j]=int(a[2])
    #print(a)
#print(x,y,z)
if (sum(x)==0 & sum(y)==0 & sum(z)==0):
    print('YES')
else:
    print('NO')