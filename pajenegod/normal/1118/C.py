import sys
range = xrange
input = raw_input

n = int(input())
numbs = [int(x) for x in sys.stdin.read().split()]
big = 1001
counter = [0]*big
for i in numbs:counter[i]+=1

out = [[0]*n for _ in range(n)]

j = 0
for x in range(n):
    for y in range(n):
        while j<big and counter[j]<4:j += 1
        if j==big:break

        if out[x][y]==0 and x!=n-1-x and y!=n-1-y:
            out[x][y] = j
            out[n-1-x][y] = j
            out[x][n-1-y] = j
            out[n-1-x][n-1-y] = j

            counter[j] -= 4
j = 0
for x in range(n):
    for y in range(n):
        while j<big and counter[j]<2:j += 1
        if j==big:break

        if out[x][y]==0 and x==n-1-x and y!=n-1-y:
            out[x][y] = j
            out[x][n-1-y] = j

            counter[j] -= 2
j = 0
for x in range(n):
    for y in range(n):
        while j<big and counter[j]<2:j += 1
        if j==big:break

        if out[x][y]==0 and x!=n-1-x and y==n-1-y:
            out[x][y] = j
            out[n-1-x][y] = j

            counter[j] -= 2
j = 0
for x in range(n):
    for y in range(n):
        while j<big and counter[j]<1:j += 1
        if j==big:break

        if out[x][y]==0 and x==n-1-x and y==n-1-y:
            out[x][y] = j

            counter[j] -= 1

if sum(counter)==0 and all(x!=0 for row in out for x in row):
    print 'YES'
    out = [' '.join(str(x) for x in row) for row in out]
    print '\n'.join(out)
else:
    print 'NO'