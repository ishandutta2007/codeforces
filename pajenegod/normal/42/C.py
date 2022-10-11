import sys
sys.modules['hashlib'] = sys
import random
range = xrange
input = raw_input
 
A = [int(x) for x in input().split()]
 
out = []
while A != [1,1,1,1]:# and (A.count(1) != 3 or A.count(2) != 1):
    i = 0
    while i < 4 and not(A[i] & 1 == A[i - 1] & 1 == 0):
        i += 1
    if i < 4:
        A[i] //= 2
        A[i - 1] //= 2
        out.append('/%d' %(1 + (i-1)%4))
        continue
    i = random.randint(0,3)
    A[i - 1] += 1
    A[i] += 1
    out.append('+%d' %(1 + (i-1)%4))
 
if A == [1,1,1,1]:
    print '\n'.join(str(x) for x in out)
else:
    print -1