#include<bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC optimize("-O3")

const int MAXN = 1007;

int a[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    vector<int> ans(n);
    for (int i = 1; i < n - 1; ++i)
    {
        ans[i] = sqrt(a[i][i - 1] * a[i][i + 1] / a[i - 1][i + 1]);
    }
    ans[0] = a[0][1] / ans[1];
    ans[n - 1] = a[n - 2][n - 1] / ans[n - 2];
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}