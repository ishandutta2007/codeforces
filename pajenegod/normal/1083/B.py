import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

if k == 1:
    print n
    sys.exit()

A = input()
B = input()

count = 0

# Equal
i = 0
while i < n and A[i] == B[i]:
    i += 1

count += 2 * n - i

i += 1

free = [0]*n
while i < n:
    if A[i] == 'a':
        free[i] += 1
    if B[i] == 'b':
        free[i] += 1
    i += 1

k -= 2

extra = 0
for i in range(n):
    cur = min(extra + free[i], k)

    k -= cur
    count += (n - i) * cur
    extra += cur

print count