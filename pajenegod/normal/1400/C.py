import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    S = [ord(c) - ord('0') for c in input()]
    x = int(input())

    n = len(S)

    W = [1] * n
    for i in range(n):
        if S[i] == 0:
            if 0 <= i - x:
                W[i - x] = 0
            if i + x < n:
                W[i + x] = 0

    T = [0] * n
    for i in range(n):
        if 0 <= i - x and W[i - x]:
            T[i] = 1
        if i + x < n and W[i + x]:
            T[i] = 1
    
    if S == T:
        print ''.join(str(x) for x in W)
    else:
        print -1