a, b = map(int, input().split())
while (a != 0 and b != 0 and min(a, b) * 2 <= max(a, b)):
    if (a >= 2 * b):
        a, b = a - 2 * b * ((a - 2 * b) // (2 * b) + 1), b
        if (b < 0):
            b += 2 * a
    elif (b >= 2 * a):
        a, b = a, b - 2 * a * ((b - 2 * a) // (2 * a) + 1)
        if (a < 0):
            a += 2 * b
print(a, b)