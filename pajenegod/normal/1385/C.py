import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    A.reverse()

    i = 1
    while i < n and A[i - 1] <= A[i]:
        i += 1
    while i < n and A[i - 1] >= A[i]:
        i += 1
    print n - i