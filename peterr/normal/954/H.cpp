#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 5000;
int a[MAXN];
int ainv[MAXN];
int cross[MAXN][MAXN];
int paths[2 * MAXN];
int temp[2 * MAXN];

int modpow(int b, int e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) ((long long) ans * b % MOD);
        b = (int) ((long long) b * b % MOD);
        e >>= 1;
    }
    return ans;
}

int modinv(int x)
{
    return modpow(x, MOD - 2);
}

int chooseTwo(int x)
{
    if (x < 2)
        return 0;
    return (int) ((long long) x * (x - 1) / 2 % MOD);
}

int add(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    a[0] = ainv[0] = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] = (int) ((long long) a[i] * a[i - 1] % MOD);
        ainv[i] = modinv(a[i]);
        cross[i][i] = (int) ((long long) a[i] * a[i] % MOD);
        for (int j = 1; j < i; j++)
        {
            cross[j][i] = (int) ((long long) 2 * a[i] * a[j] % MOD);
            if (j + 1 <= i - 1)
                cross[j][i] = add(cross[j][i], cross[j + 1][i - 1]);
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        int children = (int) ((long long) a[i] * ainv[i - 1] % MOD);
        int pairs = chooseTwo(children);
        int extra = modinv((int) ((long long) a[i] * a[i] % MOD));
        for (int j = 1; j <= 2 * n - 2; j++)
        {
            temp[j] = add(temp[j], (int) ((long long) children * paths[j] % MOD));
            if (i + j <= n)
                temp[j] = add(temp[j], (int) ((long long) a[i + j - 1] * ainv[i - 1] % MOD));
            if (j >= 2 && j <= (n - i) * 2)
            {
                int mn = max(0, j - 2 - (n - 1 - i));
                int mx = min(n - 1 - i, j - 2);
                if (mx >= mn)
                {
                    int ways = (int) ((long long) pairs * cross[i + mn][i + mx] % MOD);
                    temp[j] = add(temp[j], (int) ((long long) ways * extra % MOD));
                }
            }
        }
        copy(temp, temp + 2 * n, paths);
        fill(temp, temp + 2 * n, 0);
    }
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        cout << paths[i] << " ";
    }
    cout << "\n";
    return 0;
}