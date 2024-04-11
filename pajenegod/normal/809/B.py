import sys
range = xrange
input = raw_input

# x dist <= y dist
def query(x,y):
    print 1, x + 1, y + 1
    sys.stdout.flush()
    return input() == 'TAK'

def solve(x,y):
    print 2,x+1,y+1
    sys.exit()

n,k = [int(x) for x in input().split()]

a = 0
b = n - 1
while a<b:
    c = a + b >> 1
    if query(c,c+1):
        b = c
    else:
        a = c + 1
# first found at a
pos1 = a


a = 0
b = pos1 - 1
while a < b:
    c = a + b >> 1
    if query(c,c+1):
        b = c
    else:
        a = c + 1

if a == b and query(a, pos1):
    pos2 = a
else:
    a = pos1 + 1
    b = n - 1
    while a < b:
        c = a + b >> 1
        if query(c + 1, c):
            a = c + 1
        else:
            b = c
    pos2 = a

solve(pos1, pos2)