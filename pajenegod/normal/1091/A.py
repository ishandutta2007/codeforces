import sys
input = raw_input
range = xrange

y,b,r = [int(x) for x in input().split()]

works = -1
for i in range(200):
    if i<=y and i+1<=b and i+2<=r:
        works = i
print works*3+3