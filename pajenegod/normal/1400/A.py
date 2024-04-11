import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()
    T = S[n - 1] * n
    print T