import sys

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    def threes(B):
        maxcount = 0
        for a in A:
            besta = 10**18
            for b in B:
                aa = a - b
                if aa >= 0 and aa % 3 == 0:
                    besta = min(besta, aa // 3)
            maxcount = max(maxcount, besta)
        return maxcount

    alt1 = threes([0])
    alt2 = threes([0, 1]) + 1
    alt3 = threes([0, 2]) + 1
    alt4 = threes([0, 2, 4]) + 2
    alt5 = threes([0, 1, 2, 3]) + 2
    alt6 = threes([0, 1, 2, 3, 4, 5]) + 3


    print(min(alt1, alt2, alt3, alt4, alt5, alt6))