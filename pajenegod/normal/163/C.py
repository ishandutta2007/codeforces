import sys
range = xrange
input = raw_input

n,L,v1,v2 = [int(x) for x in input().split()]

L2 = 2 * L
L3 = 3 * L
n2 = 2 * n

l = L/(1.0 + v1*1.0/v2)

A = [int(x) for x in input().split()]
B = [a + L3 for a in A]
A += [a + L2 for a in A]
A += B

x = 0.0
i = 0
j = 0
count = [0.0]*(n + 1)

while j < n2 and A[j] < x + l:
    j += 1

while x != L2:
    nextx = min(A[j] - l, A[i], L2)
    count[j - i] += nextx - x
    if nextx == A[i]:
        i += 1
    elif nextx != L2:
        j += 1
    x = nextx

print '\n'.join(str(x / L2) for x in count)