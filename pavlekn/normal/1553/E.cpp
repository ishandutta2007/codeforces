#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
        }
        int K = 75;
        vector<int> used(n);
        vector<int> ans;
        for (int __ = 0; __ < K; ++__)
        {
            int u = rng() % n;
            if (n <= K)
            {
                u = __ % n;
            }
            int st = u;
            int val = (st - a[st] + n) % n;
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                used[i] = false;
            }
            cnt = 1;
            used[u] = true;
            for (int i = 0; i < n; ++i)
            {
                if (used[i])
                {
                    continue;
                }
                u = i;
                ++cnt;
                while (!used[u])
                {
                    used[u] = true;
                    u = (a[u] + val + n) % n;
                }
            }
            if (n - cnt <= m)
            {
                ans.push_back(val);
            }
        }
        sort(ans.begin(), ans.end());
        int pr = -1;
        vector<int> res;
        for (auto el : ans)
        {
            if (el != pr)
            {
                pr = el;
                res.push_back(el);
            }
        }
        cout << res.size() << " ";
        for (auto el : res)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}