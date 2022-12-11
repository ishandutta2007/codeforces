def main():
    n, m = map(int, input().split())
    a = []
    ans = [0] * n
    for i in range(m):
        x, y, z = map(int, input().split())
        ans[y - 1] = m + 1
        a.append([y - 1, x - 1, z, i + 1])
    a.sort()
    for i in range(m):
        count = 0
        for j in range(a[i][1], a[i][0]):
            if (count == a[i][2]):
                break
            if (ans[j] == 0):
                ans[j] = a[i][3]
                count += 1
        if (count < a[i][2]):
            print(-1)
            return
    for i in range(n):
        print(ans[i], end=' ')
main()