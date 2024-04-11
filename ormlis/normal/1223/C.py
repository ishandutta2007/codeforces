q = int(input())


def check(l):
    return sum(i * j // 100 for i, j in zip(prices[-l:], sorted(p[:l]))) >= k


for i in range(q):
    n = int(input())
    prices = sorted(map(int, input().split()))
    x, a = map(int, input().split())
    y, b = map(int, input().split())
    k = int(input())
    p = [0] * n
    for j in range(n):
        c = 0
        if (j + 1) % a == 0:
            c += x
        if (j + 1) % b == 0:
            c += y
        p[j] = c
    if not check(n):
        print(-1)
    else:
        left = -1
        right = n
        while right - left > 1:
            middle = (right + left) // 2
            if check(middle):
                right = middle
            else:
                left = middle
        print(right)