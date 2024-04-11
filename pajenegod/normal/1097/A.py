import sys
range = xrange
input = raw_input

a = input()
for b in input().split():
    if b[0] in a or b[1] in a:
        print 'YES'
        sys.exit()

print 'NO'