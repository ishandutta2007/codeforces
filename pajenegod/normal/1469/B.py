import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    R = [int(x) for x in input().split()]
    m = int(input())
    B = [int(x) for x in input().split()]

    r_cumsum = maxr_cumsum = 0
    for r in R:
        r_cumsum += r
        maxr_cumsum = max(maxr_cumsum, r_cumsum)
    
    b_cumsum = maxb_cumsum = 0
    for b in B:
        b_cumsum += b
        maxb_cumsum = max(maxb_cumsum, b_cumsum)

    print maxr_cumsum + maxb_cumsum