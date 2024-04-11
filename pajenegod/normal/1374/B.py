import sys
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())

    count3 = 0
    while n % 3 == 0:
        n //= 3
        count3 += 1
    
    count2 = 0
    while n % 2 == 0:
        n //= 2
        count2 += 1

    if n != 1 or count2 > count3:
        print -1
        continue

    print count3 + (count3 - count2)