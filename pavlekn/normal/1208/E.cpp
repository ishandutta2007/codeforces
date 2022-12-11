#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k, m;
    cin >> k >> m;
    vector<int> ans(m);
    vector<int> op(m);
    vector<int> cl(m);
    for (int _ = 0; _ < k; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        if (2 * n <= m)
        {
            int mx = 0;
            for (int i = 0; i < n; ++i)
            {
                mx = max(mx, a[i]);
                ans[i] += mx;
            }
            mx = 0;
            for (int i = m - 1; i >= m - n; --i)
            {
                mx = max(mx, a[i - m + n]);
                ans[i] += mx;
            }
            op[n] += mx;
            cl[m - n] -= mx;
        }
        else
        {
            set<pair<int, int>> s;
            for (int i = 0; i < m; ++i)
            {
                if (i < n)
                {
                    s.insert({-a[i], i});
                }
                if (-(s.begin()->first) < 0 && (i >= n || i + n < m))
                {

                }
                else
                {
                    ans[i] += -(s.begin()->first);
                }
                if (m - n <= i)
                {
                    s.erase({-a[i - m + n], i - m + n});
                }
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < m; ++i)
    {
        cur += op[i];
        cur += cl[i];
        ans[i] += cur;
    }
    for (int i = 0; i < m; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}