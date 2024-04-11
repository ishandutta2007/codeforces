import math

A=input().split()

x1 = int(A[0])
y1 = int(A[1])

A=input().split()

x2 = int(A[0])
y2 = int(A[1])

dx = abs(x1-x2)
dy = abs(y1-y2)
ans = max(dx,dy)
print(ans)