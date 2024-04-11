def main():
    n, k, l = map(int, input().split())
    m = n * k
    a = list(map(int, input().split()))
    a.sort()
    f = a[0]
    i = 0
    while (i < m and a[i] <= f + l):
        i += 1
    if (i != m):
        i -= 1
    else:
        ans = 0
        ind = 0
        for i in range(n):
            ans += a[ind]
            ind += k
        print(ans)
        return
    last = i
    if (last + 1 < n):
        print(0)
        return
    count = m - last - 1
    ost = last + 1
    ans = 0
    i = last
    while (i >= 0):
        c = min(k - 1, count)
        count -= c
        i -= (k - c)
        ans += a[i + 1]
    print(ans)
main()