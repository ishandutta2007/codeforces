import sys
range = xrange
input = sys.stdin.readline

n = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

base1 = [0]*n
base2 = [0]*n

base1[-1] = B[-1]
base2[-1] = A[-1]

for i in reversed(range(n-1)):
    base1[i] = B[i] + A[i+1] + base1[i+1]
    base2[i] = A[i] + B[i+1] + base2[i+1]

scale1 = [0]*n
scale2 = [0]*n

scale1[-1] = B[-1]
scale2[-1] = A[-1]


for i in reversed(range(n-1)):
    scale1[i] = base1[i+1] + A[i+1] + (2*(n-i-1)+1)*B[i] + scale1[i+1]
    scale2[i] = base2[i+1] + B[i+1] + (2*(n-i-1)+1)*A[i] + scale2[i+1]


besta = 0
y = 0
t = 0
points = 0
for i in range(n):
    if y == 0:
        points += t*A[i]
        score = scale1[i] + t*base1[i] + points
        t+=1
        points += B[i]*t
    else:
        points += t*B[i]
        score = scale2[i] + t*base2[i] + points
        t+=1
        points += A[i]*t
    besta = max(besta,score)

    y = 1-y
    t+=1

print besta