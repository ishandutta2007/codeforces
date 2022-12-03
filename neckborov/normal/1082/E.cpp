//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define float long double
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> mega_set;

void dota47()
{
    /// vk.com/gotovseros
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef _47
    freopen("love.cpp", "r", stdin), freopen("karasek.cpp", "w", stdout);
#endif
}

const int MAX_N = 5e5 + 47;

int n, m, cnt[MAX_N], a[MAX_N], pref[MAX_N], first[MAX_N];

vector<int> g[MAX_N], dp[MAX_N];

signed main()
{
    dota47();
    cin >> n >> m;
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + (a[i] == m);
        cnt[a[i]]++;
        best = max(best, cnt[a[i]]);
        g[a[i]].push_back(i);
        dp[a[i]].push_back(47);
    }
    for (int i = n; i >= 1; i--)
    {
        if (first[a[i]] != 0)
        {
            continue;
        }
        first[a[i]] = i;
    }
    for (int x = 1; x < MAX_N; x++)
    {
        if (x == m || g[x].size() == 0)
        {
            continue;
        }
        set<pair<int, int>> s;
        int sum = 0;
        dp[x][g[x].size() - 1] = g[x].size() - 1;
        for (int j = (int)(g[x].size() - 1); j > 0; j--)
        {
            int r = g[x][j];
            int l = g[x][j - 1];
            sum += (pref[r] - pref[l]);
            sum--;
            s.insert({sum, l});
            //auto [mx, ind] = *prev(s.end());
            int mx = prev(s.end())->first;
            int ind = prev(s.end())->second;
            if (mx > 0)
            {
                dp[x][j - 1] = lower_bound(g[x].begin(), g[x].end(), ind) - g[x].begin();
            }
            else
            {
                dp[x][j - 1] = g[x].size() - 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == m)
        {
            continue;
        }
        int l = i;
        int r = dp[a[i]][(lower_bound(g[a[i]].begin(), g[a[i]].end(), l) - g[a[i]].begin())];
        r = g[a[i]][r];
        if (r < l)
        {
            continue;
        }
        int len = 0;
        len = upper_bound(g[a[i]].begin(), g[a[i]].end(), r) - g[a[i]].begin();
        len = len - (lower_bound(g[a[i]].begin(), g[a[i]].end(), l) - g[a[i]].begin());
        best = max(best, len + pref[l - 1] - pref[0] + pref[n] - pref[r]);
    }
    cout << best;
    return 0;
}