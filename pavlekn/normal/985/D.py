def main():
    n, h = map(int, input().split())
    l = -1
    r = 10 ** 18
    while (r - l != 1):
        m = (r + l) // 2
        t = m + h - 1
        if (m > h):
            if (t % 2 == 1):
                j = t // 2 + 1 - h + 1
                s = j * (j + 1) // 2 + j * (h - 1) + (m - j) * (m - j + 1) // 2
                if (s >= n):
                    r = m
                else:
                    l = m
            else:
                j = t // 2 - h + 1
                s = j * (j + 1) // 2 + j * (h - 1) + (m - j) * (m - j + 1) // 2
                if (s >= n):
                    r = m
                else:
                    l = m
        else:
            s = m * (m + 1) // 2
            if (s >= n):
                r = m
            else:
                l = m
    print(r)
main()