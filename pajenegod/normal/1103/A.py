import sys
range = xrange
input = raw_input


out = []

move0 = 0
move1 = 0
for s in raw_input():
    if s=='0':
        out.append([(1,1),(1,3)][move0])
        move0 = (move0 + 1)%2
    elif s=='1':
        out.append([(3,1),(3,2),(3,3),(3,4)][move1])
        move1 = (move1 + 1)%4
print '\n'.join(' '.join(str(x) for x in reversed(X)) for X in out)