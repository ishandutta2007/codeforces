#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e3 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(20);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < 20; ++j)
        {
            if (a[i] & (1 << j))
            {
                ++cnt[j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < 20; ++j)
        {
            if (cnt[j] > i)
            {
                cur |= (1 << j);
            }
        }
        ans += cur * cur;
    }
    cout << ans << endl;
    return 0;
}