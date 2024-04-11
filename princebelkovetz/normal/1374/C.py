from sys import stdin, stdout, setrecursionlimit
from math import ceil
for i in range(int(input())):
    n = int(input())
    s = input()
    ans = 0
    while True:
        cou = []
        ok1 = ans
        for i in range(n):
            if s[i] == '(':
                cou.append(s[i])
            else:
                if len(cou) == 0:
                    ans += 1
                    s = s[:i] + s[i + 1:] + s[i]
                    break
                else:
                    cou.pop()
        ok2 = ans
        if ok1 == ok2: break
    print(ans)