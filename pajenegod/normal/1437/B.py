import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input()]

    count0 = count1 = 0
    for i in range(n - 1):
        count0 += A[i] == A[i + 1] == 0
        count1 += A[i] == A[i + 1] == 1
    print max(count0, count1)