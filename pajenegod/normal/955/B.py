import sys
from collections import defaultdict as di

range = xrange
input = raw_input

s = input()
D = di(int)
for c in s:
    D[c]+=1

G = []
for c in D:
    G.append(D[c])
G.sort()


if len(G)<2 or len(G)>4:
    print('No')
    sys.exit()


if len(G)==2:
    if G[0]>=2 and G[1]>=2:
        print('Yes')
    else:
        print('No')
elif len(G)==3:
    if G[2]>1:
        print('Yes')
    else:
        print('No')
elif len(G)==4:
    print('Yes')