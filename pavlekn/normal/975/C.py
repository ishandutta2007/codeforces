def main():
    n, q = map(int, input().split())
    ans = []
    a = list(map(int, input().split()))
    k = list(map(int, input().split()))
    b = []
    w = 0
    for i in range(n):
        w += a[i]
        b.append(w)
    s = sum(a)
    cur = 0
    for m in range(q):
        cur += k[m]
        if (cur >= s):
            cur = 0
        l = -1
        r = n - 1
        while (r - l != 1):
            m = (l + r) // 2
            if (b[m] > cur):
                r = m
            else:
                l = m
        ans.append(l)
    for i in range(q):
        print((n - 1) - ans[i])
main()