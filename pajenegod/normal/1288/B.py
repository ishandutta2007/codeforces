import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    A,B = [int(x) for x in input().split()]
    count = 0
    c = 0
    while 10 * c + 9 <= B:
        c = 10 * c + 9
        count += 1

    print A * count