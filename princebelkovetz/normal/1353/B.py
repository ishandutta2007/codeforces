from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = sorted([int(i) for i in input().split()])
    b = sorted([int(i) for i in input().split()], reverse = True)
    for i in range(k):
        if a[i] > b[i]: break
        else: a[i], b[i] = b[i], a[i]
    print(sum(a))