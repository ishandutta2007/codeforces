import sys
range = xrange
input = raw_input

C = [int(input()) for _ in range(4)]

if all(c==0 for c in C):
    print 1
elif (C[0]==0 or C[3]==0) and C[2]>0:
    print 0
elif C[0]==C[3]:
    print 1
else:
    print 0