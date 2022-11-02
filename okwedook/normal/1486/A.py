t = int(input())
for i in range(t):
    n = int(input())
    need = 0
    have = 0
    ans = True
    a = [int(i) for i in input().split()]
    for j in range(n):
        need += j
        have += a[j]
        if have < need:
            ans = False
    if ans:
        print("YES")
    else:
        print("NO")