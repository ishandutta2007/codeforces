import sys
range = xrange
input = raw_input

n,q = [int(x) for x in input().split()]
inp = [int(x)-1 for x in sys.stdin.read().split()]
L = inp[::2]
R = inp[1::2]

paint = [0]*n
for i in range(q):
    for j in range(L[i],R[i]+1):
        paint[j]+=1

besta = 10**9
best_rem = None
for i in range(q):
    cost = 0
    for j in range(L[i],R[i]+1):
        paint[j]-=1
        if paint[j]==0:
            cost += 1
    one_count = [0]
    for c in paint:
        one_count.append(one_count[-1] + (1 if c==1 else 0))

    for k in range(q):
        if k==i:continue
        score = one_count[R[k]+1] - one_count[L[k]] + cost
        if score < besta:
            besta = score
            best_rem = (i,k)
    for j in range(L[i],R[i]+1):
        paint[j]+=1

i,k = best_rem
for j in range(L[i],R[i]+1):
    paint[j]-=1
for j in range(L[k],R[k]+1):
    paint[j]-=1

print sum(1 for _ in paint if _>0)