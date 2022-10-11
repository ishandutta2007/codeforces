import sys, collections
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

marker = [-1]*(n + 1)
counter = collections.defaultdict(lambda: -1)
counter[0] = 0
total = 0

l = -1
s = 0
for i in range(n):
    a = A[i]
    s += a
    l = max(l, counter[s])
    counter[s] = i + 1

    total += i - l

print total