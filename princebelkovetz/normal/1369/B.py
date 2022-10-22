for _ in range(int(input())):
    n = int(input())
    s = input()
    curi = 0
    ans = ""
    f = True
    while curi < n:
        len1 = 0
        len2 = 0
        while curi < n and s[curi] == '1':
            curi += 1
            len1 += 1
        if curi == n:
            ans += s[n - len1:]
        elif len1 == 0:
            ans += s[curi]
            curi += 1
        else:
            while curi < n and s[curi] == '0':
                curi += 1
                len2 += 1
            if f:
                f = False
                ans += '0'
    print(ans)