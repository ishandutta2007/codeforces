import sys
from decimal import *
range = xrange
input = raw_input
getcontext().prec = 20

n,U = [int(x) for x in input().split()]
E = [int(x) for x in input().split()]

best_ind = -1
best_val = Decimal(-1)
j = 0
for i in range(n-2):
    while j-i<=1:
        j+=1
    while j+1<n and E[j+1]-E[i]<=U:
        j+=1
    if E[j]-E[i]<=U:
        val = Decimal(E[j]-E[i+1])/Decimal(E[j]-E[i])
        if val>best_val:
            best_val = val
print('{:.20f}'.format(best_val))
#print(float(best_val))