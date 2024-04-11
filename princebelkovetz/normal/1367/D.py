from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    s = input()
    n = int(input())
    a = [int(i) for i in input().split()]
    l = {}
    for x in s:
        if x not in l:
            l[x] = 1
        else:
            l[x] += 1
    s = set(s)
    t = ""
    for x in s:
        t += x
    t = sorted(t, reverse=True)
    ans = [0] * n
    j = 1
    h = {}
    while 0 in ans:
        cur = []
        for i in range(n):
            if a[i] == 0 and ans[i] == 0:
                ans[i] = j
                cur.append(i)
        for i in range(n):
            if ans[i] > 0:
                continue
            for x in cur:
                a[i] -= abs(i - x)
        h[j] = len(cur)
        j += 1

    itog = [0] * n
    curi = 0
    for key in h:
        while l[t[curi]] < h[key]:
            curi += 1
        for i in range(n):
            if ans[i] == key:
                itog[i] = t[curi]
        curi += 1
    for x in itog:
        print(x, end ="")
    print()