import sys
range = xrange
input = sys.stdin.readline

n,d = [int(x) for x in input().split()]
X = [int(x) for x in input().split()]

cand = []
for x in X:
    cand.append(x+d)
    cand.append(x-d)

pos_cand = set()
for c in cand:
    mindist = 10**12
    for x in X:
        mindist=min(mindist,abs(x-c))
    if mindist==d:
        pos_cand.add(c)
print len(pos_cand)