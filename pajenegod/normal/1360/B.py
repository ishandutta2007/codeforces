import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    n = inter()
    S = inters()
    S.sort()

    biggest_diff = S[1] - S[0]
    for i in range(n - 1):
        biggest_diff = min(biggest_diff, S[i + 1] - S[i])
    print biggest_diff