import sys

import random



n = int(input())
if n<=3:
    print('YES')
    sys.exit()
coord = [int(x) for line in sys.stdin for x in line.split()]


X = [coord[2*i] for i in range(n)]
Y = [coord[2*i+1] for i in range(n)]


for i in range(13):
    a = random.randint(0,n-1)
    b = random.randint(0,n-2)
    
    if a==b:
        b+=1
    
    x0,y0 = X[a],Y[a]
    x1,y1 = X[b],Y[b]
    
    dx = x1-x0
    dy = y1-y0
    not_on_line = []
    for c in range(n):
        if c==a or c==b:
            continue
        x2,y2 = X[c],Y[c]
        Dx = x2-x0
        Dy = y2-y0
        if dx*Dy-dy*Dx!=0:
            not_on_line.append(c)
    if len(not_on_line)<=1:
        print('YES')
        sys.exit()


    a = not_on_line[0]
    b = not_on_line[1]
    x0,y0 = X[a],Y[a]
    x1,y1 = X[b],Y[b]
    
    dx = x1-x0
    dy = y1-y0
    can = True
    for c in not_on_line:
        if c==a or c==b:
            continue
        x2,y2 = X[c],Y[c]
        Dx = x2-x0
        Dy = y2-y0
        if dx*Dy-dy*Dx!=0:
            can = False
            break
    if can:
        print('YES')
        sys.exit()
print('NO')