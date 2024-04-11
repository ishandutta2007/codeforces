#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7;

int cnt[MAXN];
int m[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a.begin(), a.end());
    for (int i = k - 1; i > 0; --i)
    {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> m[i];
    }
    int l = 0;
    int r = n;
    while (r - l > 1)
    {
        int med = (l + r) / 2;
        int fl = true;
        for (int i = k; i > 0; --i)
        {
            if (cnt[i] > m[i] * med)
            {
                fl = false;
            }
        }
        if (fl)
        {
            r = med;
        }
        else
        {
            l = med;
        }
    }
    cout << r << endl;
    vector<vector<int>> ans(r);
    for (int i = 0; i < n; ++i)
    {
        ans[i % r].push_back(a[i]);
    }
    for (int i = 0; i < r; ++i)
    {
        cout << ans[i].size() << " ";
        for (auto el : ans[i])
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}