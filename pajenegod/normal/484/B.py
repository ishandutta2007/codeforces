import sys
range = xrange
input = raw_input

maxi = 0
n = int(input())
A = [int(x) for x in input().split()]

big = 10**6 + 1
count = [0]*(2*big)
for a in A:
    count[a] = 1

prevs = []
prev = -1
for i in range(2 * big):
    prevs.append(prev)
    if count[i]:
        prev = i

for i in range(1, big):
    if count[i]:
        for j in range(2*i, big + i, i):
            maxi = max(maxi, i - j + prevs[j])

print maxi