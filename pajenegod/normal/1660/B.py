import sys
input = sys.stdin.readline

def printer(b):
    if b:
        print 'YES'
    else:
        print 'NO'

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    A.sort()

    if len(A) == 1:
        printer(A[0] <= 1)
    else:
        printer(A[-1] - 1 <= A[-2])