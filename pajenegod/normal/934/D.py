import sys
range = xrange
input = raw_input

p,k = [int(x) for x in input().split()]

coeff = []
while p!=0:
    coeff.append(p%k)
    p//=k
    p*=-1
print len(coeff)
print ' '.join(str(c) for c in coeff)