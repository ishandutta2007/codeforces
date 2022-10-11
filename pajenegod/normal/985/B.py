import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

data = [int(x) for line in sys.stdin for x in line.rstrip()]
# n switches
# every row is one switch


super_switch = [0]*m
for y in range(n):
    ind = y*m
    for x in range(m):
        super_switch[x]+=data[ind+x]


for y in range(n):
    ind = y*m
    special = False
    for x in range(m):
        if data[ind+x]==1 and super_switch[x]==1:
            special = True
            break
    if not special:
        print 'YES'
        sys.exit()
print 'NO'