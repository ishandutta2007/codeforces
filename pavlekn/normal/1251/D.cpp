#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, s;
        cin >> n >> s;
        vector<pair<int, int>> a(n);
        int st = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i].second >> a[i].first;
            st += a[i].second;
        }
        sort(a.begin(), a.end());
        int l = 0;
        int r = s + 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2ll;
            vector<int> b;
            for (int i = 0; i < n; ++i)
            {
                if (a[i].first >= m)
                {
                    b.push_back(a[i].second);
                }
            }
            int fl = true;
            if (b.size() <= n / 2ll)
            {
                fl = false;
            }
            sort(b.begin(), b.end());
            int cur = 0;
            for (int i = 0; i < b.size(); ++i)
            {
                if (b.size() - i <= (n + 1) / 2ll && b[i] < m)
                {
                    cur += m - b[i];
                }
            }
            if (cur + st <= s && fl)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        cout << l << endl;
    }
    return 0;
}