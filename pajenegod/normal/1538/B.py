import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    s = sum(A)
    if s % n != 0:
        print -1
        continue
    
    goal = s // n

    print sum(1 for a in A if a > goal)