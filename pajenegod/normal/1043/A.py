import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

k = 0
while True:
    k+=1
    s = 0
    for a in A:
        if k-a<0:
            break
        s += k-a
    else:
        if s>sum(A):
            break
print k