#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx2")

unordered_map<int, vector<int>> t;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        t[0].push_back(i);
    }
    long long cc = 0;
    for (int i = 29; i >= 0; --i)
    {
        long long cnt1 = 0;
        long long cnt0 = 0;
        for (auto el : t)
        {
            int c0 = 0;
            int c1 = 0;
            for (auto e : el.second)
            {
                if (a[e] & (1 << i))
                {
                    cnt1 += c0;
                    ++c1;
                }
                else
                {
                    cnt0 += c1;
                    ++c0;
                }
            }
        }
        if (i != 0)
        {
            t = {};
            for (int j = 0; j < n; ++j)
            {
                t[(a[j] >> i) << i].push_back(j);
            }
        }
        if (cnt1 < cnt0)
        {
            ans |= (1 << i);
        }
        cc += (long long)min(cnt0, cnt1);
    }
    cout << cc << " " << ans << endl;
    return 0;
}