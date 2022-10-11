import sys
range = xrange
input = raw_input

n = int(input())

O = []

a = n//4
b = (n-a)//3
c = (n-a-b)//2
d = n-a-b-c

for x in range(d):
    O.append((x,0))
for x in range(c):
    O.append((-x-1,0))
for y in range(b):
    O.append((0,y+1))
for y in range(a):
    O.append((0,-y-1))

print '\n'.join(str(a)+' '+str(b) for a,b in O)