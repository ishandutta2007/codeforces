import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    P = [int(x) for x in input().split()]
    
    cost = 0

    Psum = [0]
    for p in P:
        Psum.append(p + Psum[-1])

    for i in range(1, n):
        total = Psum[i] + cost
        p = P[i]
        #while (100 * p + total - 1) // total > k:
        #    total += 1
        #    cost += 1

        x = max(total, (100 * p + k - 1) // k)
        cost += x - total
        total = x
    print cost