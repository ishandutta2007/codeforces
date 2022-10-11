import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    S = input()
    count = [0]*2
    for c in S:
        count[int(c)] += 1
    if min(count) & 1:
        print 'DA'
    else:
        print 'NET'