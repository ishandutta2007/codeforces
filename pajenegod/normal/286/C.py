import sys
range = xrange
input = raw_input

n = int(input())
P = [int(x) for x in input().split()]

for i in [int(x) - 1 for x in input().split()][1:]:
    P[i] *= -1

stack = []
for i in reversed(range(n)):
    p = P[i]
    if (not stack) or stack[-1] != p:
        stack.append(abs(p))
        P[i] = -abs(p)
    else:
        stack.pop()

if not stack:
    print 'YES'
    print ' '.join(str(x) for x in P)
else:
    print 'NO'