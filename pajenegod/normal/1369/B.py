import sys
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    A = [ord(c) - ord('0') for c in input()[:n]]

    i = 0
    while i < n and A[i] == 0:
        i += 1

    j = n - 1
    while j >= 0 and A[j] == 1:
        j -= 1

    if i - 1 == j:
        print '0' * i + '1' * (n - 1 - j)
    else:
        print '0' * (i + 1) + '1' * (n - 1 - j)