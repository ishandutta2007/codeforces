import sys
range = xrange
input = raw_input

def checker(A, goal):
    s = sum(A)
    for a in A:
        if s - a == goal:
            return a
    return -1

t = int(input())
for _ in range(t):
    n = int(input())
    B = [int(x) for x in input().split()]
    B.sort()

    A = B[:n + 1]
    x = checker(A, B[-1])
    if x >= 0:
        A.remove(x)
        print ' '.join(str(x) for x in A)
        continue

    A = B[:n] + [B[-1]]
    x = checker(A, B[-2])
    if x >= 0:
        A.remove(x)
        print ' '.join(str(x) for x in A)
        continue

    print -1