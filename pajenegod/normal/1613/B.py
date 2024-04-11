import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    A.sort()
    for i in range(n//2):
        print(A[~i], A[0])