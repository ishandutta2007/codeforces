def solve():
    m = 0
    c = ''
    s = list(map(float, input().split()))
    f = ['x', 'y', 'z']
    d = solve2(s.copy())
    if d:
        return print(d)
    s2 = sorted(s)
    flag = False
    if s2[0] < 2:
        s2 = s2[1:] + s2[:1]
    if s2[0] < 2:
        s2[0], s2[1] = s2[1], s2[0]
    try:
        if s2[1] * s2[2] > s2[1] ** s2[2]:
            flag = True
    except:
        pass

    ans = []
    used = [0] * 3
    for i in range(3):
        j = s.index(s2[i])
        while used[j]:
            j = s.index(s2[i], j + 1, 3)
        ans.append(f[j])
        used[j] = 1
    if flag:
        if f.index(ans[2]) < f.index(ans[1]):
            ans[1], ans[2] = ans[2], ans[1]
        print(f'({ans[0]}^{ans[1]})^{ans[2]}')
    else:
        print(f'{ans[0]}^{ans[1]}^{ans[2]}')


def solve2(s):
    m = 0
    c = ''
    f = ['x', 'y', 'z']
    for i in range(3):
        for j in range(2):
            for e in range(3):
                if e == i:
                    continue
                cur = 0
                try:
                    if j == 0:
                        cur = (s[i]) ** ((s[e]) ** s[(3 ^ e) ^ i])
                        if cur > m:
                            m = cur
                            c = f'{f[i]}^{f[e]}^{f[(3 ^ e) ^ i]}'
                    else:
                        cur = (s[i]) ** (s[e] * s[(3 ^ e) ^ i])
                        if cur > m:
                            m = cur
                            c = f'({f[i]}^{f[e]})^{f[(3 ^ e) ^ i]}'
                except OverflowError:
                    return ''
    return c


solve()