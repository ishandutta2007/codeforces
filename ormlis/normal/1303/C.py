def solve():
    s = input()
    c = s[0]
    s = s[1:]
    last = 0
    used = {}
    for i in s:
        used[c[last]] = 1
        if last + 1 != len(c):
            if c[last + 1] == i:
                last += 1
                continue
        if last:
            if c[last - 1] == i:
                last -= 1
                continue
        if used.get(i, 0) == 1:
            print("NO")
            return
        if last + 1 == len(c):
            last += 1
            c += i
            continue
        if last == 0:
            c = i + c
            continue
        print("NO")
        return
    used[c[last]] = 1
    for i in range(26):
        if used.get(chr(ord('a') + i), 0) == 0:
            c += chr(ord('a') + i)
    print("YES")
    print(c)



for i in range(int(input())):
    solve()