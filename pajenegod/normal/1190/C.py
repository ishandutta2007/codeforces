import sys
range = xrange
input = raw_input

first = [1e9]*2
last = [0]*2

n,k = [int(x) for x in input().split()]
for i,a in enumerate(int(x) for x in input()):
    first[a] = min(first[a], i)
    last[a] = i

for a in [0,1]:
    if last[a] - first[a] + 1 <= k:
        print 'tokitsukaze'
        sys.exit()

for a in [0,1]:
    if last[a] - first[a] + 1 > k + 1 or \
        first[a] >= k or n - 1 - last[a] >= k:
        print 'once again'
        sys.exit()
print 'quailty'