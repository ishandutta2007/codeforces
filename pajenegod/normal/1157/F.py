import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

big = 2*10**5+10
count = [0]*big
for a in A:
    count[a] += 1

best = -1
bestl = -1
bestr = -1

i = 0
while i<big:
    while i<big and count[i]==0:
        i += 1
    if i==big:break
    s = count[i]

    j = i+1
    while j<big and count[j]>=2:
        s += count[j]
        j += 1

    maybe = j
    if maybe<big and count[maybe]==1:
        s += count[maybe]
        maybe += 1

    if s>best:
        best = s
        bestl = i
        bestr = maybe
    i = j


heights = []
for i in range(bestl,bestr):
    heights += [i]*count[i]

out = heights[::2] + heights[1::2][::-1]
print len(out)
print ' '.join(str(x) for x in out)