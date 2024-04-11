import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()] + [-2]
amax = max(A)

prev = -1
count = 0
maxcount = 1
for a in A:
    if a==prev==amax:
        count += 1
    else:
        maxcount = max(maxcount,count)
        count = 1
        prev = a

print maxcount