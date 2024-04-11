a, b, c, d = map(int, input().split())

if b - a == c - b == d - c:
    print(d + (d - c))
elif b * b == a * c and c * c == b * d and (d * d) % c == 0:
    print((d * d) // c)
else:
    print(42)