from sys import stdin


def solve():
    n, m = map(int, input().split())
    d = {}
    d2 = {}
    v = stdin.readlines()
    for i in range(n):
        d.setdefault(v[i].strip(), []).append(i)
    s = []
    o = []
    for i in range(n):
        st = v[i].strip()
        st2 = st[::-1]
        if d.get(st) and d.get(st2):
            if st == st2:
                if len(d[st]) > 1:
                    s.append((st, len(d[st]) // 2))
                    if len(d[st]) % 2 == 0:
                        d[st] = []
                        continue
                o.append(st)
                d[st] = []
                continue
            s.append((st, min(len(d[st2]), len(d[st]))))
            d[st] = []
            d[st2] = []
    l = 0
    p = ""
    for el in s:
        l += el[1]
        p += el[0]
    if o:
        p = p + max(o, key=lambda x: len(x)) + p[::-1]
    else:
        p = p + p[::-1]
    print(len(p))
    print(p)

for i in range(1):
    solve()