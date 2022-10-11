import sys
range = xrange
input = raw_input

n = int(input())
A = [abs(int(x)) for x in input().split()]
A.sort()
ans = 0

j = 0
for i in range(n):
    x = A[i]
    while j<n:
        y = A[j]
        if abs(x-y)<=abs(x)<=abs(x+y) and abs(x-y)<=abs(y)<=abs(x+y):
            j += 1
        else:
            break
    ans += j-i-1
print ans