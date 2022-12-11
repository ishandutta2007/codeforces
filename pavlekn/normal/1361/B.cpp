#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int fl = false;
int fl2 = false;

int pw(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a;
    }
    int cur = pw(a, n / 2);
    cur *= cur;
    if (cur >= mod)
    {
        fl2 = true;
    }
    cur %= mod;
    if (n % 2)
    {
        cur *= a;
        if (cur >= mod)
        {
            fl2 = true;
        }
    }
    return cur % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _ = 0; _ < tt; ++_)
    {
        fl = false;
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<pair<int, int>> t;
        int cnt = 1;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] == a[i - 1])
            {
                ++cnt;
            }
            else
            {
                t.push_back({a[i - 1], cnt});
                cnt = 1;
            }
        }
        t.push_back({a[n - 1], cnt});
        reverse(t.begin(), t.end());
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < t.size(); ++i)
        {
            if (i != 0)
            {
                fl2 = false;
                cur *= pw(p, t[i - 1].first - t[i].first);
                if (cur != 0 && fl2)
                {
                    fl = true;
                }
                if (cur >= mod)
                {
                    cur = 0;
                    fl = true;
                }
                ans *= pw(p, t[i - 1].first - t[i].first);
                ans %= mod;
            }
            if (fl)
            {
                ans -= t[i].second;
                continue;
            }
            int d = min(cur, t[i].second);
            cur -= d;
            ans -= d;
            if ((t[i].second - d) % 2 == 1)
            {
                ++cur;
                ++ans;
            }
        }
        ans *= pw(p, t[t.size() - 1].first);
        ans %= mod;
        if (ans < 0)
        {
            ans += mod;
        }
        cout << ans << "\n";
    }
    return 0;
}