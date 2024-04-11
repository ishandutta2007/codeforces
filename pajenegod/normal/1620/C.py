import sys

t = int(input())
for _ in range(t):
    n,k,x = [int(x) for x in input().split()]
    x -= 1

    A = [+(c == '*') for c in input()]
    AA = []
    for a in A:
        if AA and AA[-1] > 0 and a > 0:
            AA[-1] += a
        else:
            AA.append(a)
    n = len(AA)

    B = [1] * (n + 1)
    for i in reversed(range(n)):
        B[i] = (k * AA[i] + 1) * B[i + 1]

    S = []
    for i in range(n):
        if AA[i]:
            count,x = divmod(x, B[i + 1])
            S += ['b'] * count
        else:
            S += ['a']
    print(''.join(S))