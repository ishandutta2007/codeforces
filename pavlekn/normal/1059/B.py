def main():
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        s = input()
        b = []
        for l in s:
            b.append(l)
        a.append(b)
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            may = True
            if (a[i][j - 1] == '.' or a[i][j + 1] == '.' or a[i + 1][j - 1] == '.' or a[i + 1][j + 1] == '.' or a[i + 1][j] == '.' or a[i - 1][j - 1] == '.' or a[i - 1][j + 1] == '.' or a[i - 1][j] == '.'):
                may = False
            if (may):
                a[i][j - 1] = a[i][j + 1] = a[i + 1][j - 1] = a[i + 1][j + 1] = a[i + 1][j] = a[i - 1][j - 1] = a[i - 1][j + 1] = a[i - 1][j] = '?'
    for i in range(n):
        for j in range(m):
            if (a[i][j] == '#'):
                print("NO")
                return
    print("YES")
main()