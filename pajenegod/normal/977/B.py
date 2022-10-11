import sys
range = xrange
input = raw_input
from collections import defaultdict as di

count = di(int)

n = int(input())
S = input()
for i in range(n-1):
    count[S[i],S[i+1]]+=1
besta = -1
besta_str = ''
for a,b in count:
    if count[a,b]>besta:
        besta=count[a,b]
        besta_str = ''.join([a,b])
print besta_str