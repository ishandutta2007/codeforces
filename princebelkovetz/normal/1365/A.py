from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
def f(a):
    for i in range(n):
        for j in range(m):
            cur = []
            for k in range(n):
                cur.append(a[k][j])
            if 1 not in a[i] and 1 not in cur:
                a[i][j] = 1
                return True
    return False


for _ in range(int(input())):
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append([int(i) for i in input().split()])
    ans = 1
    while f(a):
        ans = 1 - ans
    if ans == 0:
        print("Ashish")
    else:
        print("Vivek")