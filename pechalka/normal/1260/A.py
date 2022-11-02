n = int(input())
for i in range(n):
    c, s = map(int, input().split())
    print((s // c) ** 2 * (c - s % c) + (s // c + 1) ** 2 * (s % c))