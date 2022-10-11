import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

count = [0] * 20
for a in A:
    for i in range(20):
        count[i] += (a >> i) & 1

sq = 0
for _ in range(n):
    a = 0
    for i in range(20):
        if count[i]:
            count[i] -= 1
            a |= 1 << i
    sq += a * a
print sq