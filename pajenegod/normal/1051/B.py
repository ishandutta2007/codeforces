import sys
range = xrange
input = raw_input

l,r = [int(x) for x in input().split()]
print 'YES'

out = []
i = l
while i<r:
    out.append(str(i)+' '+str(i+1))
    i+=2
print '\n'.join(out)