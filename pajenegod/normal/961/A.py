import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
# len m
C = [int(x) for x in input().split()]

counter = [0]*n
for c in C:
    counter[c-1]+=1

print min(counter)