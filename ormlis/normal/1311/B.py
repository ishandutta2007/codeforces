from sys import stdin

def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    u = [0] * n
    p = list(map(int, input().split()))
    for x in p:
        u[x-1] = 1
    p = []
    for i in range(n):
        if u[i] == 0:
            p.append(i)
    pos = 0
    prevmx = -1
    curmx = -1
    curmn = 101
    for i in range(n):
        curmn = min(a[i], curmn)
        curmx = max(a[i], curmx)
        if i == p[pos]:
            if curmn < prevmx:
                return print("NO")
            prevmx = curmx
            curmx = -1
            curmn = 101
            pos += 1
    print("YES")

for i in range(int(input())):
    solve()