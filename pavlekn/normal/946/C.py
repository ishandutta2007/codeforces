s = input()
if (len(s) < 26):
    print(-1)
else:
    ans = -1
    i = 0
    pos = 0
    while (pos < len(s) and i < 26):
        if (ord(s[pos]) <= ord('a') + i):
            s = s[:pos] + chr(ord('a') + i) + s[pos + 1:]
            i += 1
        pos += 1
    if (i == 26):
        print(s)
    else:
        print(-1)