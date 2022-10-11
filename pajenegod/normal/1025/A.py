import sys
range = xrange

input = sys.stdin.readline

orda = ord('a')

n = int(input())
s = [ord(c)-orda for c in raw_input()]


array = [0]*30
for c in s:
    array[c]+=1
if any(a>1 for a in array) or n==1:
    print 'Yes'
else:
    print 'No'