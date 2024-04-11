def solve():
    s = input()
    l = len(s)
    ans = []
    cur1 = cur2 = ''
    va = {'t', 'tw', 'two'}
    va2 = {'o', 'on', 'one'}
    for i in range(l):
        if cur1 + s[i] in va:
            cur1 += s[i]
        elif s[i] in va:
            cur1 = s[i]
        else:
            cur1 = ''
        if cur2 + s[i] in va2:
            cur2 += s[i]
        elif s[i] in va2:
            cur2 = s[i]
        else:
            cur2 = ''
        if cur1 == 'two':
            if i + 1 >= l or s[i + 1] != 'o':
                ans.append(i + 1)
                cur1 = 'tw'
                cur2 = ''
            else:
                ans.append(i)
                cur1 = ''
        elif cur2 == 'one':
            ans.append(i)
            cur2 = ''
    print(len(ans))
    print(*ans)


t = int(input())
for _ in range(t):
    solve()