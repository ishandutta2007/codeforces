from math import ceil

for _ in range(int(input())):
    n = int(input())
    s = input()
    cntalr = 0
    cntpos = []
    ok = "abacaba"
    for i in range(n - 6):
        cur = s[i:i + 7]
        if cur == ok:
            cntalr += 1
        else:
            cnt = 0
            for j in range(7):
                if i + j == n:
                    break
                if s[i + j] == '?':
                    cnt += 1
                elif s[i + j] == ok[j]:
                    cnt += 1
            if cnt == 7:
                cntpos.append(i)
    if cntalr >= 2:
        print("No")
    elif cntalr == 1:
        print("Yes")
        for i in range(n):
            if s[i] == '?':
                print('z', end="")
            else:
                print(s[i], end="")
        print()
    else:
        c = True
        for x in cntpos:
            t = s[:x] + ok + s[x + 7:]
            cou = 0
            for i in range(n - 6):
                cur = t[i:i + 7]
                if cur == ok:
                    cou += 1
            if cou == 1:
                print("Yes")
                for i in range(n):
                    if t[i] == '?':
                        print('z', end="")
                    else:
                        print(t[i], end="")
                print()
                c = False
                break
        if c:
            print("No")