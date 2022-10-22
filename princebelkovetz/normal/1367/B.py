from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n = int(input())
    a = [int(i) % 2 for i in input().split()]
    cou0 = cou1 = 0
    for x in a:
        if x == 0: cou0 += 1
        else: cou1 += 1
    x = 0
    if cou0 == cou1 + n % 2:
        for i in range(n):
            if i % 2 != a[i]:
                x += 1
        print(x // 2)
    else:
        print(-1)