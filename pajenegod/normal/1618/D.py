import sys

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    if k == 0:
        print(sum(A))
        continue

    A.sort()

    s = 0
    for a,b in zip(A[-2 * k: -k], A[-k:]):
        s += a // b

    s += sum(A[:-2*k])
    print(s)