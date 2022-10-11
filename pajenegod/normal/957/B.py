import sys
from collections import defaultdict as di

range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
data = [c for _ in range(n) for c in input()]
next_x = di(lambda:-1)
next_y = di(lambda:-1)

prev_x = di(lambda:-1)
prev_y = di(lambda:-1)
for x in range(m):
    for y in range(n):
        if data[x+y*m]=='#':
            ix = x+1
            while ix<m and data[ix+y*m]=='.':
                ix+=1
            if ix<m:
                next_x[x,y]=ix
            iy = y+1
            while iy<n and data[x+iy*m]=='.':
                iy+=1
            if iy<n:
                next_y[x,y]=iy
            ix = x-1
            while ix>=0 and data[ix+y*m]=='.':
                ix-=1
            if ix>=0:
                prev_x[x,y]=ix
            iy = y-1
            while iy>=0 and data[x+iy*m]=='.':
                iy-=1
            if iy>=0:
                prev_y[x,y]=iy
found = set()
for x in range(m):
    for y in range(n):
        if (x,y) not in found and data[x+y*m]=='#':
            ys_of_same_X = di(set)
            #Y = di(list)
            #print('searching from',x,y)
            Q = [(x,y)]
            while Q:
                ix,iy = Q.pop()
                if (ix,iy) in found:
                    continue
                found.add((ix,iy))
                ys_of_same_X[ix].add(iy)
                if next_x[ix,iy]!=-1:
                    Q.append( (next_x[ix,iy],iy) )
                if next_y[ix,iy]!=-1:
                    Q.append( (ix,next_y[ix,iy]) )
                if prev_x[ix,iy]!=-1:
                    Q.append( (prev_x[ix,iy],iy) )
                if prev_y[ix,iy]!=-1:
                    Q.append( (ix,prev_y[ix,iy]) )
            root = -1
            #print(ys_of_same_X)
            for iy in ys_of_same_X:
                root = ys_of_same_X[ix]
                break
            for iy in ys_of_same_X:
                #print(root,ys_of_same_X[iy])
                if root!=ys_of_same_X[iy]:
                    print('No')
                    sys.exit()
print('Yes')