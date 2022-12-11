#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); srand(clock());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        vector<int> t;
        int sm = 0;
        char pr = 'L';
        for (auto el : s)
        {
            if (el == 'W')
            {
                ++ans;
                if (pr == 'W')
                {
                    ++ans;
                }
                else
                {
                    if (ans > 1)
                    {
                        t.push_back(cnt);
                    }
                }
                cnt = 0;
            }
            else
            {
                ++sm;
                ++cnt;
            }
            pr = el;
        }
        k = min(sm, k);
        if (ans == 0)
        {
            if (k > 0)
            {
                ans += (k - 1) * 2;
                ++ans;
            }
            cout << ans << endl;
        }
        else
        {
            sort(t.begin(), t.end());
            ans += 2 * k;
            int cur = 0;
            for (auto el : t)
            {
                if (el + cur <= k)
                {
                    cur += el;
                    ++ans;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}