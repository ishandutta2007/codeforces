#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<int> cnt;
        int cur = 0;
        int cc = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                cnt.push_back(cur);
                ++cc;
                cur = 0;
            }
            else
            {
                ++cur;
            }
        }
        if (cnt.size() == 0)
        {
            cout << (a + b) * n + b << endl;
            continue;
        }
        int ans = 0;
        ans += (cnt[0] + cur + 3) * a + (cnt[0] + cur + 4) * b;
        for (int i = 1; i < cnt.size(); ++i)
        {
            if (cnt[i] < 2)
            {
                ans += 2 * (cnt[i] + 1) * b + (cnt[i] + 1) * a;
            }
            else
            {
                ans += (cnt[i] + 3) * b + (cnt[i] + 1) * a + min(2 * a, (cnt[i] - 1) * b);
            }
        }
        cout << ans << endl;
    }
    return 0;
}