n = int(input())

if n > 0:
    print(n)
else:
    s = str(-n)
    s = s[::-1]
    n1 = 0
    if len(s) >= 3:
        n1 = s[0] + s[2:]
    else:
        n1 = s[0]
    n1 = int(n1[::-1])
    n2 = s[1:]
    n2 = int(n2[::-1])
    n = min(n1, n2)
    print(-n)