import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

Aodd = [A[i] if i&1 else 0 for i in range(n)]
Aeven = [A[i] if i&1==0 else 0 for i in range(n)]

Acumodd = [0]
Acumeven = [0]
for a in Aodd:
    Acumodd.append(Acumodd[-1]+a)
for a in Aeven:
    Acumeven.append(Acumeven[-1]+a)

count = 0
for i in range(n):
    #first = A[:i]
    #second = A[i+1:]

    #c = first+second
    #if sum(c[::2])==sum(c[1::2]):
    #    count += 1
    odd = Acumodd[i]-Acumodd[0] + Acumeven[-1] - Acumeven[i+1]
    even = Acumeven[i]-Acumeven[0] + Acumodd[-1] - Acumodd[i+1]
    
    if odd==even:
        count += 1
print count