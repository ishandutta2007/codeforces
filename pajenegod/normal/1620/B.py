import sys
input = sys.stdin.buffer.readline

t = int(input())
for _ in range(t):
    w,h = [int(x) for x in input().split()]
    X1 = [int(x) for x in input().split()]
    X2 = [int(x) for x in input().split()]
    Y1 = [int(x) for x in input().split()]
    Y2 = [int(x) for x in input().split()]
    X1.pop(0); X2.pop(0); Y1.pop(0); Y2.pop(0)

    ans = 0
    for A,b in (X1, h), (Y1, w), (X2, h), (Y2, w):
        ans = max(ans, (A[-1] - A[0]) * b)
    print(ans)