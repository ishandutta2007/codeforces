def solve():
    i = 0
    j = 0
    imax = imin = 0
    jmax = jmin = 0
    fjmin = ljmin = fjmax = ljmax = fimax = limax = fimin = limin = -1
    for ind, e in enumerate(input()):
        if e == 'W':
            i += 1
            if i > imax:
                imax = i
                fimax = ind
                limax = ind
        elif e == 'S':
            i -= 1
            if i < imin:
                imin = i
                fimin = ind
                limin = ind
        elif e == "A":
            j -= 1
            if j < jmin:
                jmin = j
                fjmin = ind
                ljmin = ind
        elif e == 'D':
            j += 1
            if j > jmax:
                jmax = j
                fjmax = ind
                ljmax = ind
        if j == jmin:
            ljmin = ind
        if j == jmax:
            ljmax = ind
        if i == imin:
            limin = ind
        if i == imax:
            limax = ind
    ans = 0
    if fjmax > ljmin + 1 or fjmin > ljmax + 1:
        ans = imax - imin + 1
    if fimax > limin + 1 or fimin > limax + 1:
        ans = max(ans, jmax - jmin + 1)
    print((imax - imin + 1) * (jmax - jmin + 1) - ans)


for _ in range(int(input())):
    solve()