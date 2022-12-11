#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = d;
        map<int, int> cnt;
        int cur = 0;
        for (int i = 0; i < d; ++i)
        {
            if (cnt[a[i]] == 0)
            {
                ++cur;
            }
            cnt[a[i]]++;
        }
        ans = cur;
        for (int i = 0; i + d < n; ++i)
        {
            cnt[a[i]]--;
            if (cnt[a[i]] == 0)
            {
                --cur;
            }
            if (cnt[a[i + d]] == 0)
            {
                ++cur;
            }
            cnt[a[i + d]]++;
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}