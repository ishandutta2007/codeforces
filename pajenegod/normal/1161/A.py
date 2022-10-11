import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

X = [int(x)-1 for x in input().split()]

first_time = [m]*n

for i in reversed(range(m)):
    first_time[X[i]] = i

last_time = [-1]*n
for i in range(m):
    last_time[X[i]] = i


ans = 0
for i in range(n):
    for dx in (-1,0,1):
        if 0<=i+dx< n and last_time[i]<first_time[i+dx]:
            ans += 1

print ans