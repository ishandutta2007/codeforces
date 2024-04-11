import sys
range = xrange
input = raw_input

n = int(input())

inp = []
for c in input():
    if c=='R':
        inp.append(0)
    elif c=='G':
        inp.append(1)
    else:
        inp.append(2)

arg = 'RGB'

cost = [[1]*3 for _ in range(n)]
P = [[-1]*3 for _ in range(n)]
cost[0][inp[0]]=0

opp = [[k for k in range(3) if k!=j] for j in range(3)]

for i in range(1,n):
    for j in range(3):
        k = min(opp[j],key=lambda k: cost[i-1][k])
        cost[i][j] = cost[i-1][k] + int(inp[i]!=j)
        P[i][j] = k


k = min(range(3),key=lambda k:cost[-1][k])
cost = cost[-1][k]
out = []
for i in reversed(range(n)):
    out.append(k)
    k = P[i][k]
print cost
print ''.join(arg[k] for k in reversed(out))