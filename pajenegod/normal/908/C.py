import math
def collide(x1,r1,x2,r2,y2):
    y = r1
    D = (r1+r2)**2-(x1-x2)**2
    if D>=0:
        y = max(y,math.sqrt(D)+y2)
    return y
n,r = [int(x) for x in input().split()]
X = [int(x) for x in input().split()]
Y = []
for i in range(n):
    y = r
    for j in range(i):
        y = max(y,collide(X[i],r,X[j],r,Y[j]))
    Y.append(y)
print(*Y)