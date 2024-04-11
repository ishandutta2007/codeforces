import sys
range = xrange 
input = raw_input

x = int(input())

seen = set()
while x not in seen:
    seen.add(x)
    x = int(str(x+1).rstrip('0'))

print len(seen)