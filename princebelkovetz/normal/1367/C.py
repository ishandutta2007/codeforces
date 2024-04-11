from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    s = '1' + '0' * k + s + '0' * k + '1'
    cou = 0
    a = []
    for i in range(len(s)):
        if s[i] == '1':
            a.append(i)
    # print(a)
    for i in range(1, len(a)):
        cou += (a[i] - a[i - 1] - 1 - k) // (k + 1)
    print(cou)