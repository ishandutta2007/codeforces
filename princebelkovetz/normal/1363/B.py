from sys import stdin, stdout, setrecursionlimit
input = stdin.readline

for _ in range (int(input())):
    s = input()
    n = len(s)
    cou = 0
    for i in range(n):
        if s[i] == '0':
            cou += 1
    x = cou
    ans = cou
    for i in range(n):
        if s[i] == '0':
            cou -= 1
        elif s[i] == '1':
            cou += 1
        ans = min(cou, ans)
    cou = x
    for i in range(n - 1, -1, -1):
        if s[i] == '0':
            cou -= 1
        elif s[i] == '1':
            cou += 1
        ans = min(cou, ans)
    print(ans)