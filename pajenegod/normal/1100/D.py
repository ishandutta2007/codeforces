import sys
from collections import defaultdict as di
range = xrange
input = raw_input

taken_pos = set()

w = 999
h = 999

X,Y = [int(x)-1 for x in input().split()]

pos = [(3,3)]*666
dangersY = [0]*w
dangersX = [0]*h
for i in range(666):
    x,y = [int(x)-1 for x in input().split()]
    pos[i]=(x,y)
    dangersY[y] += 1
    dangersX[x] += 1
    taken_pos.add((x,y))

count = 0
goal_X = 499
goal_Y = 499

while count<2000 and (X!=goal_X or Y!=goal_Y):
    if X<goal_X:
        dx = 1
    elif X==goal_X:
        dx = 0
    else:
        dx = -1
    
    if Y<goal_Y:
        dy = 1
    elif Y==goal_Y:
        dy = 0
    else:
        dy = -1



    if (X+dx,Y+dy) in taken_pos:
        if dx!=0:
            print X+dx+1,Y+1
            sys.stdout.flush()
            X += dx
        else:
            print X+1,Y+dy+1
            sys.stdout.flush()
            Y += dy
    else:
        print X+dx+1,Y+dy+1
        sys.stdout.flush()
        X += dx
        Y += dy

    k,x,y = [int(x)-1 for x in input().split()]
    if k<0:
        sys.exit()
    old_x,old_y = pos[k]
    dangersY[old_y] -= 1
    dangersX[old_x] -= 1
    taken_pos.remove((old_x,old_y))
    
    pos[k] = (x,y)
    dangersY[y] += 1
    dangersX[x] += 1
    taken_pos.add((x,y))

    count += 1

quads = [0]*4
for i in range(666):
    x,y = pos[i]
    if x>499:
        if y>499:
            quads[0] += 1
        else:
            quads[3] += 1
    else:
        if y>499:
            quads[1] += 1
        else:
            quads[2] += 1

j = min(range(4),key=lambda i:quads[i])

if j==0:
    goal_X = 998
    goal_Y = 998
elif j==2:
    goal_X = 0
    goal_Y = 0
elif j==1:
    goal_X = 0
    goal_Y = 998
else:
    goal_X = 998
    goal_Y = 0

while count<2000:
    goal_X = 998-goal_X
    goal_Y = 998-goal_Y
    
    while count<2000 and (X!=goal_X or Y!=goal_Y):
        if X<goal_X:
            dx = 1
        elif X==goal_X:
            dx = 0
        else:
            dx = -1
        
        if Y<goal_Y:
            dy = 1
        elif Y==goal_Y:
            dy = 0
        else:
            dy = -1

        if (X+dx,Y+dy) in taken_pos:
            if dx!=0:
                print X+dx+1,Y+1
                sys.stdout.flush()
                X += dx
            else:
                print X+1,Y+dy+1
                sys.stdout.flush()
                Y += dy
        else:
            print X+dx+1,Y+dy+1
            sys.stdout.flush()
            X += dx
            Y += dy

        k,x,y = [int(x)-1 for x in input().split()]
        if k<0:
            sys.exit()
        
        old_x,old_y = pos[k]
        dangersY[old_y] -= 1
        dangersX[old_x] -= 1
        taken_pos.remove((old_x,old_y))
        
        pos[k] = (x,y)
        dangersY[y] += 1
        dangersX[x] += 1
        taken_pos.add((x,y))
        
        count += 1