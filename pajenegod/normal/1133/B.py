import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
D = [int(x) for x in input().split()]

modder = [0]*k
count = 0
for d in D:
    if modder[(k-d)%k]>0:
        modder[(k-d)%k]-=1
        count += 1
    else:
        modder[d%k]+=1
print 2*count