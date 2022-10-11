import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

ways = [0] * (n + 1)
ways[-1] = 1
for i in reversed(range(n)):
    ways[i] = sum(ways[j] for j in range(i+1, min(i + 2, n) + 1))

search = []
i = 0
while k and i < n:
    for j in range(i + 1, min(i+2, n) + 1):
        if ways[j] >= k:
            search += reversed(range(i, j))
            i = j
            break
        else:
            k -= ways[j]
#assert(search[-1] == n - 1)
assert(k==1)


print ' '.join(str(x+1) for x in search)