import sys
input = raw_input
xrange = range
n=int(input())
count = 0
for i in range(1,10**5+1):
    leaders = i
    left = n-i
    if left>0 and left%leaders==0:
        count += 1
print count