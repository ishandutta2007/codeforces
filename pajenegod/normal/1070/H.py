import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n = int(input())
filenames = [input() for _ in range(n)]
m = int(input())
queries = [input() for _ in range(m)]

count = di(int)
ref = {}
for f in filenames:
    subs = []
    for i in range(len(f)):
        for j in range(i+1,len(f)+1):
            subs.append(f[i:j])
    for sub in set(subs):
        count[sub]+=1
        ref[sub]=f
out = []
for q in queries:
    c = count[q]
    if c==0:
        out.append('0 -')
    else:
        out.append(str(c)+' '+ref[q])
print '\n'.join(out)