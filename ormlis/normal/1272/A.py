from math import ceil


def solve():
    a = list(map(int, input().split()))
    e = round(sum(a) / 3)
    for i in range(3):
        if a[i] > e:
            a[i] -= 1
        elif a[i] < e:
            a[i] += 1
    print(abs(a[0] - a[1]) + abs(a[0] - a[2]) + abs(a[1] - a[2]))


q = int(input())
for i in range(q):
    solve()