from sys import stdin, stdout


def check(lim, arr):
    if int(arr[0]) < lim or int(arr[1]) < lim:
        return False
    return max(0, int(arr[0]) - lim) + max(0, int(arr[1]) - lim) + int(arr[2]) >= lim


if __name__ == "__main__":

    q = int(stdin.readline())
    while q > 0:
        q = q - 1
        n = int(stdin.readline())
        a = []
        b = []
        a.append(0)
        b.append(0)

        for i in range(n):
            arr = stdin.readline().split(" ")
            a.append(int(arr[0]))
            b.append(int(arr[1]))

        dp = [1e18] * (n + 1)
        for i in range(n + 1):
            dp[i] = [1e18] * 4

        for i in range(4):
           dp[0][i] = 0

        #for i in range(n):
        #    print([dp[i][j] for j in range(4)], sep = " ")

        for i in range(0, n):
            for j in range(0, 4):
                for k in range(0, 4):
                    if(a[i] + int(j) != a[i + 1] + int(k)):
                        dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + k * b[i + 1])

        ans = 1e18
        for i in range(4):
            ans = min(ans, dp[n][i])
        ans = int(ans)
        stdout.write(str(ans) + "\n")