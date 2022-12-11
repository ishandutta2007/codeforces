#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 225;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int p, f;
        cin >> p >> f;
        int cnt1, cnt2;
        cin >> cnt1 >> cnt2;
        int s, w;
        cin >> s >> w;
        if (s > w)
        {
            swap(s, w);
            swap(cnt1, cnt2);
        }
        int ans = 0;
        for (int i = 0; i <= cnt1; ++i)
        {
            if (i * s <= p)
            {
                int c2 = min((p - i * s) / w, cnt2);
                int cur = i + c2;
                cur += min(cnt1 - i, f / s);
                cur += min(cnt2 - c2, (f - min(cnt1 - i, f / s) * s) / w);
                ans = max(ans, cur);
            }
        }
        cout << ans << endl;
    }
    return 0;
}