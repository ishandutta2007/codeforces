import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n = int(input())

A = [int(x) for x in input().split()]

count = di(int)
for x in A:
    count[x]+=1

single = [x for x in count if count[x]==1]
extra = [x for x in count if count[x]>=3]


L = []
#R = []
Lscore = 0
Rscore = 0
for x in single:
    if Lscore < Rscore:
        Lscore += 1
        L.append(x)
    else:
        Rscore += 1
        #R.append(x)

for x in extra:
    if Lscore<Rscore:
        Lscore += 1
        L.append(x)
        
#       for _ in range(count[x]-1):
#            R.append(x)
    elif Lscore>Rscore:
        
        Rscore += 1
#       R.append(x)
            
        for _ in range(count[x]-1):
            L.append(x)
if Lscore!=Rscore:
    print 'NO'
else:
    print 'YES'


    Lcount = di(int)
    for l in L:
        Lcount[l]+=1

    out = []
    for x in A:
        if Lcount[x]>0:
            out.append('A')
            Lcount[x]-=1
        else:
            out.append('B')
    print ''.join(out)