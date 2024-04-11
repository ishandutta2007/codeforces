x1, y1 = map(float, input().split())
x2, y2 = map(float, input().split())
x3, y3 = map(float, input().split())


def check(x1, y1, x2, y2, x3, y3):
    if x1 == x3 and y2 == y3:
        return True
    if x2 == x3 and y1 == y3:
        return True
    if x1 == x2 and not(min(y1, y2) < y3 < max(y1, y2)):
        return True
    if y1 == y2 and not(min(x1, x2) < x3 < max(x2, x1)):
        return True
    return False


def chek2(x1, y1, x2, y2, x3, y3):
    if x1 == x2 == x3:
        return True
    if y1 == y2 == y3:
        return True
    return False


if chek2(x1, y1, x2, y2, x3, y3):
    print(1)
elif check(x1, y1, x2, y2, x3, y3) or check(x1, y1, x3, y3, x2, y2) or check(x2, y2, x3, y3, x1, y1):
    print(2)
else:
    print(3)