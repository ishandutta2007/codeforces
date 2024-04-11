def main():
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(input())
    ans = "NO"
    count = [0] * m
    for i in range(n):
        for j in range(m):
            if (a[i][j] == '1'):
                count[j] += 1
    for i in range(n):
        ans = "YES"
        for j in range(m):
            if (count[j] == 1 and a[i][j] == '1'):
                ans = "NO"
                break
        if (ans == "YES"):
            break
    print(ans)
main()