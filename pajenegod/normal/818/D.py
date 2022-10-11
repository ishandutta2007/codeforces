import sys
range = xrange
input = raw_input

n, A = [int(x) for x in input().split()]

C = [int(x) for x in input().split()]

big = 10**6
buckets = [[] for _ in range(big + 1)]
for i in reversed(range(n)):
    buckets[C[i]].append(i)

checker = buckets[A][:]

for c in range(1, big + 1):
    B = buckets[c]
    if c == A or len(B) < len(checker):
        continue
    tmp = list(checker)
    while tmp:
        a = tmp.pop()
        b = B.pop()
        if a < b:
            break
    else:
        print c
        break
else:
    print -1