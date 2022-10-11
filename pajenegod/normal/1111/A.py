import sys
range = xrange
input = raw_input

vow = 'aeiou'

s = [c in vow for c in input()]
t = [c in vow for c in input()]

if s==t:
    print 'Yes'
else:
    print 'No'