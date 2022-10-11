import sys
range = xrange
input = raw_input

l,r = [int(x) for x in input().split()]

for i in range(l,r+1):
    s = str(i)
    if len(s) == len(set(s)):
        print s
        break
else:
    print -1