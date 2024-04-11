#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> l;
    vector<pair<int, int>> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first < a[i].second)
        {
            l.push_back({-a[i].second, i + 1});
        }
        else
        {
            r.push_back({a[i].second, i + 1});
        }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    cout << max(l.size(), r.size()) << endl;
    if (l.size() > r.size())
    {
        for (auto el : l)
        {
            cout << el.second << " ";
        }
    }
    else
    {
        for (auto el : r)
        {
            cout << el.second << " ";
        }
    }
    cout << endl;
    return 0;
}