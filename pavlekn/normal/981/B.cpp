#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q, w;
    long long ans = 0;
    cin >> n;
    set<int> a = {};
    set<int> b = {};
    vector<pair<int, int>> x = {};
    for (int i = 0; i < n; ++i)
    {
        cin >> q >> w;
        x.push_back({q, w});
        a.insert(q);
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> q >> w;
        x.push_back({q, w});
        b.insert(q);
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n + m; ++i)
    {
        if ((a.find(x[i].first) != a.end() && b.find(x[i].first) == b.end()) || (a.find(x[i].first) == a.end() && b.find(x[i].first) != b.end()))
        {
            ans += x[i].second;
        }
        else
        {
            if (i != 0 && x[i - 1].first == x[i].first)
            {
                ans += x[i].second;
            }
        }
    }
    cout << ans << endl;
}