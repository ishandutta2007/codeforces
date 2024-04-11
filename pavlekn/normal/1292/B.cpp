#include<bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e16 + 116;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    int x, y, t;
    cin >> x >> y >> t;
    vector<pair<int, int>> a;
    while (x0 < INF && y0 < INF)
    {
        a.push_back({x0, y0});
        x0 = x0 * ax + bx;
        y0 = y0 * ay + by;
    }
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(a[i].first - x) + abs(a[i].second - y) <= t)
        {
            ans = max(ans, 1ll);
        }
        int cur = 0;
        for (int j = i + 1; j < n; ++j)
        {
            cur += abs(a[j].first - a[j - 1].first) + abs(a[j].second - a[j - 1].second);
            if (cur + min(abs(a[i].first - x) + abs(a[i].second - y), abs(a[j].first - x) + abs(a[j].second - y)) <= t)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}