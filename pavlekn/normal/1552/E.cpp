#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, k;
    cin >> n >> k;
    int m = n * k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    vector<int> ans1(n);
    vector<int> ans2(n);
    vector<int> used(n);
    int cnt = 0;
    while (cnt < n)
    {
        vector<int> c(n);
        for (int i = 0; i < m; ++i)
        {
            if (used[a[i]])
            {
                continue;
            }
            if (c[a[i]])
            {
                ans1[a[i]] = c[a[i]];
                ans2[a[i]] = i + 1;
                used[a[i]] = true;
                ++cnt;
                if (cnt == n)
                {
                    break;
                }
                for (int j = 0; j < n; ++j)
                {
                    c[j] = 0;
                }
            }
            c[a[i]] = i + 1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << ans1[i] << " " << ans2[i] << endl;
    }
    return 0;
}