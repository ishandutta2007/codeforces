import sys
range = xrange
input = raw_input

def printer(x,y):
    print y+1,x+1
    sys.exit()
h,w,k = [int(x) for x in input().split()]

if k<h:
    printer(0,k)

k-=h

row = k//(w-1)
dx = k%(w-1)
if row%2==0:
    printer(1+dx,h-1-row)
else:
    printer(w-1-dx,h-1-row)