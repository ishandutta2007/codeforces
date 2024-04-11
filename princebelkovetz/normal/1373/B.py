from sys import stdin, stdout, setrecursionlimit
from math import ceil
for i in range(int(input())):
    s = input()
    ans = 0
    while '0' in s and '1' in s:
        for i in range(len(s) - 1):
            # print(i)
            if (s[i] == '0' and s[i + 1] == '1') or (s[i] == '1' and s[i + 1] == '0'):
                s = s[:i] + s[i + 2:]
                break
        ans = 1 - ans
    if ans == 0:
        print("NET")
    else:
        print("DA")