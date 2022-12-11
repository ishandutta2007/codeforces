#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }
    int cnt = 1;
    int ans = 0;
    multiset<pair<int, int>> s;
    s.insert({-t[a[0].second], a[0].first});
    for (int i = 1; i < n; ++i)
    {
        if (a[i].first != a[i - 1].first)
        {
            if (cnt > a[i].first - a[i - 1].first)
            {
                cnt -= (a[i].first - a[i - 1].first);
                for (int j = 0; j < a[i].first - a[i - 1].first; ++j)
                {
                    ans -= (s.begin()->first) * (a[i - 1].first - (s.begin()->second) + j);
                    s.erase(s.begin());
                }
            }
            else
            {
                for (int j = 0; j < cnt; ++j)
                {
                    ans -= (s.begin()->first) * (a[i - 1].first - (s.begin()->second) + j);
                    s.erase(s.begin());
                }
                cnt = 0;
            }
            cnt += 1;
        }
        else
        {
            ++cnt;
        }
        s.insert({-t[a[i].second], a[i].first});
    }
    for (int i = 0; i < cnt; ++i)
    {
        ans -= (s.begin()->first) * (a[n - 1].first - (s.begin()->second) + i);
        s.erase(s.begin());
    }
    cout << ans << endl;
    return 0;
}