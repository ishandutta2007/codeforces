import sys
range = xrange
input = raw_input

k = int(input())

A = [2**17 + k, 2**17    ]
B = [k        , 2**17 + k]
C = [0        ,         k]

print 3, 2
for a in A,B,C:
    print a[0], a[1]