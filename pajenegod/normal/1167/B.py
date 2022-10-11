import sys
import itertools

range = xrange
input = raw_input

A = [4,8,15,16,23,42]

mapper = {}
for a in itertools.permutations(A):
    B = []
    for i in range(4):
        B.append(a[i]*a[i+1])
    mapper[tuple(B)] = a

print '? 1 2'
print '? 2 3'
print '? 3 4'
print '? 4 5'


ans = mapper[tuple(int(input()) for _ in range(4))]
print '!',' '.join(str(x) for x in ans)