import sys
range = xrange
input = raw_input

n = int(input())
B = [int(x) for x in input().split() ]

A = [[] for _ in range(61)]
for b in B:
    A[b.bit_length() - 1].append(b)

x = 0
out = []
while len(out) < n:
    for i in range(61):
        if A[i] and not x & (1<<i):
            break
    else:
        break
    b = A[i].pop()
    out.append(b)
    x ^= b

if len(out) == n:
    print 'Yes'
    print ' '.join(str(x) for x in out)
else:
    print 'No'