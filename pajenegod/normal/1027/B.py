import sys
range = xrange
inp = [int(x) for line in sys.stdin for x in line.split()]
ii = 0

n = inp[ii]
ii+=1
q = inp[ii]
ii+=1

start = (n**2+1)//2
out = []

for _ in range(q):
    x = inp[ii]
    ii+=1
    y = inp[ii]
    ii+=1

    if (x+y)%2==0:
        out.append((y+n*(x-1)+1)//2)
    else:
        out.append((y+n*(x-1)+1)//2 + start)
print '\n'.join(str(x) for x in out)