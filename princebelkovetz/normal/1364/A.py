from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = [int(i) for i in input().split()]
    ok = []
    for i in range(n):
        if a[i] % x != 0:
            ok.append(i)
    if len(ok) == 0:
        print(-1)
    elif sum(a) % x != 0:
        print(n)
    else:
        print(max(n - ok[0] - 1, ok[-1]))