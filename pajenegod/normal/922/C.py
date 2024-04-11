import sys
input = raw_input
range = xrange

n,k = [int(x) for x in input().split()]


if k>100000:
    print 'No'
    sys.exit()

mods = set()
for i in range(1,k+1):
    if n%i in mods:
        print 'No'
        sys.exit()
    else:
        mods.add(n%i)
print 'Yes'