import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

D = di(int)

ans = 0

summa = 0
for i in range(n):
    ans += A[i]*i - summa + D[A[i] + 1] - D[A[i] - 1]

    D[A[i]] += 1
    summa += A[i]
print ans