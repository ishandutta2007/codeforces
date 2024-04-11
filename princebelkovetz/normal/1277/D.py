for _ in range (int(input())):
    n = int(input())
    a = []
    b = []
    x = {}
    cou1 = 0
    cou2 = 0
    cou3 = 0
    cou4 = 0
    for i in range(n):
        s = input()
        b.append(s)
        x[s] = True
        a.append(s[0] + s[-1])
        if a[i] == '00':
            cou1 += 1
        elif a[i] == '11':
            cou2 += 1
        elif a[i] == '10':
            cou3 += 1
        else:
            cou4 += 1
    if cou4 + cou3 == 0:
        if cou1 > 0 and cou2 > 0:
            print(-1)
        else:
            print("0\n")
    elif cou4 + cou3 == 1:
        print ("0\n")
    else:
        if abs(cou4 - cou3) <= 1:
            print("0\n")
        else:
            ans = []
            if cou4 > cou3:
                for i in range(n):
                    if a[i] == '01' and b[i][::-1] not in x:
                        cou4 -= 1
                        cou3 += 1
                        ans.append(i + 1)
                    if cou4 - cou3 <= 1:
                        break
            elif cou4 < cou3:
                for i in range(n):
                    if a[i] == '10' and b[i][::-1] not in x:
                        cou4 += 1
                        cou3 -= 1
                        ans.append(i + 1)
                    if cou3 - cou4 <= 1:
                        break
            print(len(ans))
            print(*ans)