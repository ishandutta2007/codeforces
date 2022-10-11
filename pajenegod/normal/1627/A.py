import sys

t = int(input())
for _ in range(t):
    n,m,r,c = [int(x) for x in input().split()]
    r -= 1
    c -= 1

    A = []
    for _ in range(n):
        A.append([+(c == 'B') for c in input()])

    if A[r][c]:
        print(0)
    elif any(A[r]) or any(A[i][c] for i in range(n)):
            print(1)
    elif any(any(a) for a in A):
        print(2)
    else:
        print(-1)