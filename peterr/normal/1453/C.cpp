#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
string board[MAXN];
int a[MAXN][MAXN];
int ans[10];

void tr(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            swap(a[i][j], a[j][i]);
    }
}

int solve(int dig, int n)
{
    int up = -1;
    int down = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == dig)
            {
                up = i;
                if (down == -1)
                    down = i;
            }
        }
    }
    if (up == -1)
        return 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int left = -1;
        int right = -1;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == dig)
            {
                right = j;
                if (left == -1)
                    left = j;
            }
        }
        if (right == -1)
            continue;
        if (right > left)
        {
            ans = max(ans, max((right - left) * i, (right - left) * (n - i - 1)));
        }
        ans = max(ans, max(right * (up - i), right * (i - down)));
        ans = max(ans, max((n - left - 1) * (up - i), (n - left - 1) * (i - down)));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
            for (int j = 0; j < n; j++)
            {
                a[i][j] = board[i][j] - '0';
            }
        }
        fill(ans, ans + 10, 0);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                ans[j] = max(ans[j], solve(j, n));
            }
            tr(n);
        }
        for (int i = 0; i < 10; i++)
        {
            cout << ans[i] << " \n"[i == 9];
        }
    }
    return 0;
}