#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    vector<int> cnt(x);
    int ans = 0;
    for (int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        ++cnt[n % x];
        for (; cnt[ans % x]; --cnt[ans % x], ++ans);
        cout << ans << "\n";
    }
    return 0;
}