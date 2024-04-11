for _ in range(int(input())):
    s = input()
    cntS = cntP = cntR = 0
    for x in s:
        if x == 'P': cntP += 1
        elif x == 'S': cntS += 1
        else: cntR += 1
    if cntR == max(cntR, cntS, cntP):
        print('P' * len(s))
    elif cntS == max(cntR, cntS, cntP):
        print('R' * len(s))
    elif cntP == max(cntR, cntS, cntP):
        print('S' * len(s))