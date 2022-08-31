N, M = map(int, raw_input().split(' '))
X, Y = map(int, raw_input().split(' '))
K = int(raw_input())

def valid(x, y):
    return x >= 1 and x <= N and y >= 1 and y <= M

assert valid(X, Y)
steps = 0

for k in xrange(K):
    dx, dy = map(int, raw_input().split(' '))
    lo, hi = 0, abs(N) + abs(M) + 10

    while lo + 1 < hi:
        mid = (lo + hi) // 2

        if valid(X + mid * dx, Y + mid * dy):
            lo = mid
        else:
            hi = mid

    steps += lo
    X += lo * dx
    Y += lo * dy

#print X, Y
print steps