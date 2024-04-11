#include <bits/stdc++.h>

using namespace std;

#define int long long

int cc[10];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].first = -a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    int s = 0;
    for (int i = 0; i < m * k; ++i)
    {
        s += -a[i].first;
        ans.push_back(a[i].second);
    }
    cout << s << endl;
    sort(ans.begin(), ans.end());
    for (int i = m; i < m * k; i += m)
    {
        cout << ans[i] << " ";
    }
    return 0;
}