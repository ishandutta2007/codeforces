from sys import stdin, stdout, setrecursionlimit

input = stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = [int(i) % 2 for i in input().split()]
    if 0 in a:
        print(1)
        print(a.index(0) + 1)
    else:
        if len(a) == 1:
            print(-1)
        else:
            print(2)
            lol = 0
            for i in range(n):
                if a[i] == 1:
                    print(i + 1, end = ' ')
                    lol += 1
                if lol == 2:
                    break