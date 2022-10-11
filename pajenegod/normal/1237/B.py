import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) - 1 for x in input().split()]
B = [int(x) - 1 for x in input().split()]

mapper = [0]*n
for i in range(n):
    mapper[A[i]] = i


B = [mapper[b] for b in B]

fine = 0
minfound = n
for i in reversed(range(n)):
    if minfound < B[i]:
        fine += 1
    minfound = min(minfound, B[i])
print fine