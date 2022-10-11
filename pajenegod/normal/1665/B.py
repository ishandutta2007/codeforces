### :pythonk:
import ctypes
n = 24
ctypes.memmove(id(int.__hash__) + n, id(int.__neg__) + n, 28 - n)
##


import sys
from collections import defaultdict
input = sys.stdin.readline
 
t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    
    counter = defaultdict(int)
    
    # Force counter to not do int strategy 
    counter[0.0] = 15
    del counter[0.0]
    
    for a in A:
        counter[a] += 1
 
    amax = max(A, key = lambda a: counter[a])
    acount = counter[amax]
 
    acopies = 0
    operations = 0
    while acount < n:
        if acopies == 0:
            acopies += acount
            operations += 1
 
        acopies -= 1
        acount += 1
        operations += 1
 
    print(operations)