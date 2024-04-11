import os
import sys

MAXA = 10**7 + 1


def main():
    ans = MAXA**2
    pos = [0] * MAXA
    ind = 1


    s = os.read(0, os.fstat(0).st_size)
    numb = 0; i = 0;
    while s[i] >= b'0' [0]: 
        i += 1
    while s[i] < b'0' [0]:
        i += 1
    try:
        while True:
            if s[i] >= b'0' [0]:
                numb = 10 * numb + s[i] - 48
            elif s[i] != b'\r' [0]:
                if pos[numb]:
                    if ans > numb:
                        ans = numb
                        x,y = pos[numb], ind
                else: pos[numb] = ind
                numb = 0
                ind += 1
            i += 1
    except:pass

    for i in range(1, MAXA):
        v = None
        for j in range(i, MAXA, i):
            if pos[j]:
                if v is None:
                    v = j
                else:
                    r = v * (j // i)
                    if r < ans:
                        ans = r
                        x, y = pos[v], pos[j]
                    break

    os.write(1, b"%d %d" % tuple(sorted([x, y])))


if __name__ == '__main__':
    main()