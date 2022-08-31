import math


def length(x):
    if x == 0:
        return 1
    return math.floor(math.log(x, 10)) + 1


w, m, k = map(int, input().split())
m -= 1

power = 10 ** length(m)
ans = 0

while w > 0:
    num = power - m - 1
    l = length(power) - 1

    if l * k * num <= w:
        w -= l * k * num
        ans += num
    else:
        ans += w // (l * k)
        w = 0

    m = power - 1
    power *= 10

print(ans)