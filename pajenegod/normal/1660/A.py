import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]
    
    if a == 0:
        print 1
    else:
        print a + 2 * b + 1