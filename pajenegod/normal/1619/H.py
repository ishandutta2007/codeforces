import sys
import random
 
inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
q = inp[ii]; ii += 1
 
P = inp[ii: ii + n]; ii += n
P = [i - 1 for i in P]
 
special = [+(not random.randrange(400)) for _ in range(n)]
dist = [-1] * n
nesta = [-1] * n
memory = [-2] * n
version = [-1] * (n + 1)
 
def forget(x):
    if not special[x]:
        xx = x
        special[xx] = 1
        
        x = P[x]
        while not special[x]:
            x = P[x]
        
        special[xx] = 0
        if xx == x:
            return
    version[x] += 1
 
def update(node):
    if memory[node] < version[nesta[node]]:
        d = 1
        i = P[node]
        while not special[i]:
            i = P[i]
            d += 1
        
        memory[node] = version[i]
        nesta[node] = i
        dist[node] = d
 
def walk(i, k):
    while k and not special[i]:
        k -= 1
        i = P[i]
    
    if k:
        while update(i) or dist[i] <= k:
            k -= dist[i]
            i = nesta[i]
 
    while k:
        k -= 1
        i = P[i]
    
    return i
 
for _ in range(q):
    qtype = inp[ii]; ii += 1
    if qtype == 1:
        x = inp[ii] - 1; ii += 1
        y = inp[ii] - 1; ii += 1
 
        P[x], P[y] = P[y], P[x]
 
        forget(P[x])
        forget(P[y])
    else:
        i = inp[ii] - 1; ii += 1
        k = inp[ii]; ii += 1
 
        print(walk(i, k) + 1)