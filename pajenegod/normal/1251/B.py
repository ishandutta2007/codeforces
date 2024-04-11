import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    n = int(input())
    S = [[int(x) for x in input()] for _ in range(n)]

    odd = 0
    good = 0
    bad = 0
    for s in S:
        count0 = 0
        count1 = 0
        for c in s:
            if c == 0:
                count0 += 1
            else:
                count1 += 1
        if (count0 + count1) & 1:
            odd += 1
        elif count0 & 1 == count1 & 1 == 0:
            good += 1
        else:
            bad += 1
    if odd:
        print n
    else:
        print good + 2*(bad//2)