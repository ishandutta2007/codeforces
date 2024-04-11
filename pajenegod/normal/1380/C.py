import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,x = [int(x) for x in input().split()]
    A = [int(y) for y in input().split()]
    

    A.sort()
    found = 0
    while A:
        count = 0
        mini = 10**9
        while A and count * mini < x:
            mini = A.pop()
            count += 1
        found += count * mini >= x
    print found