import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    # 1 : 1
    # 1 2 : 1
    # 1 2 3 : 2
    # 1 2 3 4 : 2
    # 1 2 3 4 5 : 3
    # 1 2 3 4 5 6 : 3
    print n + 1 >> 1