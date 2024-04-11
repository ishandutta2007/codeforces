import sys
range = xrange
input = raw_input

P = []
for i in range(2, 59):
    if not any(i % p == 0 for p in P):
        P.append(i)

numbs = []
for i in range(1, 59):
    x = 0
    for j in range(len(P)):
        if i % P[j] == 0:
            x += 1 << j
    numbs.append(x)

n = int(input())
A = [int(x) for x in input().split()]


states = 1 << 17

DP = [[0]*states]
how = []

for i in range(n):
    a = A[i]
    aa = abs(a - 1)
    
    oldDP = DP[-1]

    newDP = [d + aa for d in oldDP]
    DP.append(newDP)
    
    newHow = [1]*states
    how.append(newHow)

    for x in range(2, 59):
        xx = abs(a - x)

        y = numbs[x - 1]
        yy = ~y

        s = (states - 1) & yy
        while s:
            if newDP[s ^ y] > oldDP[s] + xx:
                newDP[s ^ y] = oldDP[s] + xx
                newHow[s ^ y] = x
            s = (s - 1) & yy
        
        if newDP[s ^ y] > oldDP[s] + xx:
            newDP[s ^ y] = oldDP[s] + xx
            newHow[s ^ y] = x

key = min(range(states), key = DP[-1].__getitem__)
ans = []
for newHow in reversed(how):
    x = newHow[key]
    ans.append(x)
    key &= ~numbs[x - 1]


print ' '.join(str(x) for x in reversed(ans))