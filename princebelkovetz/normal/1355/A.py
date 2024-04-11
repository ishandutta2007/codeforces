from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
print = stdout.write
# map(int, input().split())

for _ in range(int(input())):
    n, k = map(int, input().split())
    for i in range (k - 1):
        a = list(int(i) for i in str(n))
        mn = min(a)
        if mn == 0:
            break
        else:
            mx = max(a)
            n += mx * mn
    print(str(n) + '\n')