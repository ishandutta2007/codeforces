import sys

n=int(sys.stdin.readline())
a=sys.stdin.readline().split()
a=a+["q"]
sp="a"
c=0
y=0
for s in a:
    if s==sp:
        c=c+1
    else:
        #print('im')
        y=y+c*(c+1)/2
        c=1
    sp=s

print(y)