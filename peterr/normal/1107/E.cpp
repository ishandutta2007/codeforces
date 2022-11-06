#include <bits/stdc++.h>

using namespace std;

const long long DNE = -1000000000000LL;
const int MAXN = 100;
int arr[MAXN + 1];
long long dp[2][MAXN + 1][MAXN][MAXN];
int n;
string s;

long long get(bool one, int num, int l, int r)
{
    if (l >= 0 && l < n && r >= 0 && r < n && l <= r)
        return dp[one][num][l][r];
    if (num == 0)
        return 0;
    return DNE;
}

void update(bool one, int num, int l, int r)
{
    char key = one ? '1' : '0';
    long long best = DNE;
    if (num == 0)
    {
        for (int i = 1; i <= r - l + 1; i++)
        {
            best = max(best, arr[i] + get(0, i, l, r));
            best = max(best, arr[i] + get(1, i, l, r));
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (s[i] == key)
            {
                best = max(best, get(0, 0, l, i - 1) + get(one, num - 1, i + 1, r));
            }
        }
    }
    dp[one][num][l][r] = best;
    //cout << one << " " << num << " " << l << " " << r << " " << best << endl;
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        dp[0][0][i][i] = dp[1][0][i][i] = arr[1];
        dp[0][1][i][i] = 0;
        dp[1][1][i][i] = DNE;
        if (s[i] == '1')
            swap(dp[0][1][i][i], dp[1][1][i][i]);
        for (int j = 2; j <= n; j++)
        {
            dp[0][j][i][i] = dp[1][j][i][i] = DNE;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                update(0, j, i, i + len - 1);
                update(1, j, i, i + len - 1);
            }
            update(0, 0, i, i + len - 1);
            update(1, 0, i, i + len - 1);
        }
    }
    cout << dp[0][0][0][n - 1] << endl;
    return 0;
}