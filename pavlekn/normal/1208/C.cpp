#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e3 + 7;

int ans[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n / 4; ++i)
    {
        for (int j = 0; j < n / 4; ++j)
        {
            ans[4 * i][4 * j] = 8 + i * 4 * n + 16 * j;
            ans[4 * i][4 * j + 1] = 9 + i * 4 * n + 16 * j;
            ans[4 * i][4 * j + 2] = 1 + i * 4 * n + 16 * j;
            ans[4 * i][4 * j + 3] = 13 + i * 4 * n + 16 * j;
            ans[4 * i + 1][4 * j] = 3 + i * 4 * n + 16 * j;
            ans[4 * i + 1][4 * j + 1] = 12 + i * 4 * n + 16 * j;
            ans[4 * i + 1][4 * j + 2] = 7 + i * 4 * n + 16 * j;
            ans[4 * i + 1][4 * j + 3] = 5 + i * 4 * n + 16 * j;
            ans[4 * i + 2][4 * j] = 0 + i * 4 * n + 16 * j;
            ans[4 * i + 2][4 * j + 1] = 2 + i * 4 * n + 16 * j;
            ans[4 * i + 2][4 * j + 2] = 4 + i * 4 * n + 16 * j;
            ans[4 * i + 2][4 * j + 3] = 11 + i * 4 * n + 16 * j;
            ans[4 * i + 3][4 * j] = 6 + i * 4 * n + 16 * j;
            ans[4 * i + 3][4 * j + 1] = 10 + i * 4 * n + 16 * j;
            ans[4 * i + 3][4 * j + 2] = 15 + i * 4 * n + 16 * j;
            ans[4 * i + 3][4 * j + 3] = 14 + i * 4 * n + 16 * j;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}