from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
for _ in range(1):
    ok = {}
    n, k = map(int, input().split())
    s = input()
    mn = 9999999
    for x in s:
        if x not in ok:
            ok[x] = 1
        else:
            ok[x] += 1
    if len(ok) != k:
        print(0)
        break
    for key in ok:
        mn = min(ok[key], mn)

    print(mn * k)