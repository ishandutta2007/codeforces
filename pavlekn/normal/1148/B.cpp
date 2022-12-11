#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    //sort(a.begin(), a.end());
    //sort(b.begin(), b.end());
    if (k >= min(n, m))
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
        for (int i = 0; i <= k; ++i)
        {
            int st = a[i];
            int kk = k - i;
            int l1 = -1;
            int r1 = m;
            while (r1 - l1 > 1)
            {
                int m1 = (l1 + r1) / 2;
                if (b[m1] < st + ta)
                {
                    l1 = m1;
                }
                else
                {
                    r1 = m1;
                }
            }
            if (r1 + kk >= m)
            {
                cout << -1 << endl;
                return 0;
            }
            ans = max(ans, tb + b[r1 + kk]);
        }
    cout << ans << endl;
    return 0;
}