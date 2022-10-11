import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    
    steps = 0
    while n!=0:
        diff = n%k
        if diff==0:
            n //= k
            steps += 1
        else:
            n -= diff
            steps += diff
    print steps