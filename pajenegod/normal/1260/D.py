import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

m = inp[ii]; ii += 1
n = inp[ii]; ii += 1
k = inp[ii]; ii += 1
t = inp[ii]; ii += 1

A = inp[ii: ii + m]; ii += m

A.sort()
L = inp[ii + 0: ii + 3 * k: 3]
R = inp[ii + 1: ii + 3 * k: 3]
D = inp[ii + 2: ii + 3 * k: 3]
ii += 3 * k

lval = 0
rval = m
while lval < rval:
    mid = lval + rval + 1 >> 1
    worst = A[-mid]

    trapcount = [0]*(n + 1)
    trap = [[] for _ in range(n + 1)]
    for i in range(k):
        if D[i] > worst:
            trapcount[L[i]] += 1
            trap[R[i]].append(L[i])

    me = 0
    squad = 0
    cost = 0
    while squad < n + 1:
        if squad == n or trapcount[squad + 1] == 0:
            if squad == me:
                squad += 1
                me += 1
                cost += 1
            else:
                squad += 1
                cost += 2
        else:
            me += 1
            cost += 1
            for l in trap[me]:
                trapcount[l] -= 1
    if cost <= t:
        lval = mid
    else:
        rval = mid - 1
print rval