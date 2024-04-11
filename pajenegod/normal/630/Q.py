import sys
import math
range = xrange
input = raw_input

vol = 0

for n,l in zip([3,4,5], map(int,input().split())):
    
    base = l * l * n / (4 * math.tan(math.pi/n))
    radius = l / (2 * math.sin(math.pi/n))

    if l < radius:
        h = 0
    else:
        h = math.sqrt(l**2 - radius**2)

    vol += base * h / 3

print repr(vol)