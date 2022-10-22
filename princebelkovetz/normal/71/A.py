from sys import stdin, stdout, setrecursionlimit
for _ in range (int(input())):
    s = input()
    print(s[0], end="")
    if len(s) > 10:
        print(len(s) - 2, end="")
    else:
        print(s[1: -1], end="")
    if len(s) > 1: print(s[-1], end ="")
    print()