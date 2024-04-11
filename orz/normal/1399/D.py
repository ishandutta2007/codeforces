t = int(input())
for i in range(t):
    n = int(input())
    a = []
    s = input()
    x = set()
    y = set()
    for c in s:
        e = 0
        if c == '0':
            if len(y) == 0:
                e = len(x) + len(y) + 1
            else:
                for e in y:
                    break
                y.remove(e)
            a.append(e)
            x.add(e)
        else:
            if len(x) == 0:
                e = len(x) + len(y) + 1
            else:
                for e in x:
                    break
                x.remove(e)
            a.append(e)
            y.add(e)
    print(len(x) + len(y))
    print(*a)