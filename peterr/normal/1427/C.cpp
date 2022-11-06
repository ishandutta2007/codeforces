#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int dp[MAXN];
tuple<int, int, int> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, n;
    cin >> r >> n;
    for (int i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        a[i] = make_tuple(t, x, y);
    }
    int mx = 0;
    int ptr = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (ptr - 1 > i && get<0>(a[ptr - 1]) - get<0>(a[i]) > 2 * r)
        {
            ptr--;
            mx = max(mx, dp[ptr]);
        }
        dp[i] = 1 + mx;
        for (int j = i + 1; j < n; j++)
        {
            if (get<0>(a[j]) - get<0>(a[i]) > 2 * r)
                break;
            if (get<0>(a[j]) - get<0>(a[i]) >= abs(get<1>(a[i]) - get<1>(a[j])) + abs(get<2>(a[i]) - get<2>(a[j])))
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        //cout << i << " " << dp[i] << endl;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (get<0>(a[i]) >= get<1>(a[i]) + get<2>(a[i]) - 2)
            ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}