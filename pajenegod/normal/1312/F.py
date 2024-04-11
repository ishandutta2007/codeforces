import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    x = inp[ii]; ii += 1
    y = inp[ii]; ii += 1
    z = inp[ii]; ii += 1

    A = inp[ii: ii + n]; ii += n

    memor = {}
    def mexor(val, i):
        if val <= 0:
            return 0
        if ((val, i)) not in memor:
            A = []
            A.append(mexor(val - x, 0))
            if i != 1:
                A.append(mexor(val - y, 1))
            if i != 2:
                A.append(mexor(val - z, 2))
            if 0 not in A:
                ans = 0
            elif 1 not in A:
                ans = 1
            elif 2 not in A:
                ans = 2
            else:
                ans = 3
            memor[(val, i)] = ans
        return memor[(val, i)]

    AA = [mexor(i, 0) for i in range(250)]
    BB = [mexor(i, 1) for i in range(250)]
    CC = [mexor(i, 2) for i in range(250)]
    
    aper = 70
    while aper and AA[125 : 125 + aper] != AA[125 + aper : 125 + 2 * aper]:
        aper -= 1
    bper = 70
    while bper and BB[125 : 125 + bper] != BB[125 + bper : 125 + 2 * bper]:
        bper -= 1
    cper = 70
    while cper and CC[125 : 125 + cper] != CC[125 + cper : 125 + 2 * cper]:
        cper -= 1

    def mexor(val, i):
        if val <= 0:
            return 0
        if i == 0:
            if val < 250:
                return AA[val]
            else:
                return AA[125 + (val - 125) % aper]
        elif i == 1:
            if val < 250:
                return BB[val]
            else:
                return BB[125 + (val - 125) % bper]
        else:
            if val < 250:
                return CC[val]
            else:
                return CC[125 + (val - 125) % cper]

    xor = 0
    for a in A:
        xor ^= mexor(a, 0)

    ways = 0
    for a in A:
        newxor = xor ^ mexor(a, 0)

        if mexor(a - x, 0) == newxor:
            ways += 1
        if mexor(a - y, 1) == newxor:
            ways += 1
        if mexor(a - z, 2) == newxor:
            ways += 1
    print ways