import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

A = []
for _ in range(n):
    A.append(input())

def dire(x,y):
    if x == m - 1:
        return x,y + 1
    if y == n - 1:
        return x+1,y
    d1 = dist(x+1,y)
    d2 = dist(x,y+1)
    if d2 < d1:
        return x,y+1
    else:
        return x+1,y

def dist(x,y):
    if A[y][x] == '*':
        return 0
    if y == n - 1 and x == m - 1:
        return 100
    if x == m - 1:
        return dist(x,y+1) + 1
    if y == n - 1:
        return dist(x+1,y) + 1
    d1 = dist(x+1,y)
    d2 = dist(x,y+1)
    return min(d1,d2) + 1

score = 0
x = y = 0
while (x,y) != (m-1,n-1):
    score += A[y][x] == '*'
    x,y = dire(x,y)

score += A[y][x] == '*'
print score