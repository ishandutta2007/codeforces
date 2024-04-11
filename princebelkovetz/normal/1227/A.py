from sys import stdin, stdout, setrecursionlimit
input = stdin.readline

for _ in range (int(input())):
    n = int(input())
    a = []
    b = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append(x)
        b.append(y)
    print(max(max(a) - min(b), 0))