import sys
input = sys.stdin.readline

n,q = [int(x) for x in input().split()]

S = input().strip()
S = [ord(c) - ord('a') for c in S]

patterns = [ [0,1,2] * n,
        [0,2,1] * n,
        [1,0,2] * n,
        [1,2,0] * n,
        [2,0,1] * n,
        [2,1,0] * n]

coster = []
for pattern in patterns:
    cost = [+(S[i] != pattern[i]) for i in range(n)]
    cumsum = [0]
    for c in cost:
        cumsum.append(cumsum[-1] + c)
    coster.append(cumsum)

out = []
for _ in range(q):
    l,r = [int(x) for x in input().split()]
    l -= 1

    out.append(min(cost[r] - cost[l] for cost in coster))

print '\n'.join(str(x) for x in out)