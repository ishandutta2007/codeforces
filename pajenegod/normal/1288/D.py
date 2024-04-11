import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

A = inp[ii: ii + n * m]; ii += m

a = 0
b = 10**9
while a < b:
    c = a + b + 1 >> 1

    arr = [0]*(2**m)
    for i in range(n):
        mask = 0
        for j in range(m):
            mask = (mask << 1) | +(A[i*m + j] >= c)
        arr[mask] = 1
    
    pos = False
    goal = 2**m - 1
    for i in range(goal + 1):
        if arr[i]:
            for j in range(i + 1):
                if arr[j] and i | j == goal:
                    pos = True

    if pos:
        a = c
    else:
        b = c - 1


arr = [0]*(2**m)
who = [0]*(2**m)
for i in range(n):
    mask = 0
    for j in range(m):
        mask = (mask << 1) | +(A[i*m + j] >= a)
    arr[mask] = 1
    who[mask] = i

goal = 2**m - 1
for i in range(goal + 1):
    if arr[i]:
        for j in range(i + 1):
            if arr[j] and i | j == goal:
                print who[i] + 1, who[j] + 1
                sys.exit()