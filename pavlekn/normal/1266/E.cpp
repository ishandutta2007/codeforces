#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ans += a[i];
    }
    int q;
    cin >> q;
    map<pair<int, int>, int> used;
    for (int i = 0; i < q; ++i)
    {
        int s, t, u;
        cin >> s >> t >> u;
        if (used[{s, t}])
        {
            int u = used[{s, t}] - 1;
            used[{s, t}] = 0;
            --cnt[u];
            if (cnt[u] < a[u])
            {
                ++ans;
            }
        }
        if (u != 0)
        {
            used[{s, t}] = u;
            --u;
            ++cnt[u];
            if (cnt[u] <= a[u])
            {
                --ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}