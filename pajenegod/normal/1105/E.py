import sys
from collections import defaultdict as di
range = xrange
input = raw_input

pow2 = [2**i for i in range(50)]

n,m = [int(x) for x in input().split()]

inp = sys.stdin.read().split()
inp.append('1')

ii = 0

block = 0
name_id = {}

coupl = [pow2[_] for _ in range(m)]

summa = 0
for _ in range(n+1):
    if inp[ii] == '1':
        ii += 1 
        if block:
            for i in range(m):
                if pow2[i]&block:
                    coupl[i] |= block
        block = 0
    else:
        ii += 1
        
        name = inp[ii]
        ii += 1
        
        if name not in name_id:
            name_id[name] = 2**len(name_id)
        block |= name_id[name]


mhalf = m//2
comp = 2**mhalf-1
mem = [-1]*(2**mhalf)

def score(bitmask):
    if bitmask==comp:
        return 0
    if mem[bitmask]==-1: 
        val = 0
        for i in range(mhalf):
            if bitmask&pow2[i]==0:
                val = max(val,score((bitmask|coupl[i])&comp))
        mem[bitmask] = val+1
    return mem[bitmask]

best_count = 0
for bits in range(2**(m-mhalf)):
    bits *= 2**mhalf
    bitmask = 0
    count = 0
    for i in range(mhalf,m):
        # check if i in bits
        if bits&pow2[i]:
            # check if none of i neighbours in bits
            if bits&coupl[i]!=pow2[i]:
                break
            bitmask |= coupl[i]
            count += 1
    
    else:
        # Valid bits
        count += score(bitmask&comp)
        best_count = max(best_count,count)

print best_count