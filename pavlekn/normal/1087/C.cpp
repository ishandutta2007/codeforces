#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int n = 3;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    int min_y = 1e9;
    int max_y = -1e9;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    sort(a.begin(), a.end());
    set<pair<int, int>> ans;
    for (int i = a[0].first; i <= a[1].first; ++i)
    {
        ans.insert({i, a[0].second});
    }
    for (int i = a[1].first; i <= a[2].first; ++i)
    {
        ans.insert({i, a[2].second});
    }
    for (int i = min_y; i <= max_y; ++i)
    {
        ans.insert({a[1].first, i});
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el.first << " " << el.second << endl;
    }
    return 0;
}