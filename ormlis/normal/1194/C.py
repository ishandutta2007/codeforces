def solve():
    s = input()
    t = input()
    p = list(input())
    if len(s) > len(t):
        return print("NO")
    j = 0
    for c in s:
        while j < len(t) and c != t[j]:
            if t[j] in p:
                p.pop(p.index(t[j]))
            else:
                return print("NO")
            j += 1
        j += 1
    while j < len(t):
        if t[j] in p:
            p.pop(p.index(t[j]))
        else:
            return print("NO")
        j += 1
    if j != len(t):
        return print("NO")
    print("YES")


for _ in range(int(input())):
    solve()