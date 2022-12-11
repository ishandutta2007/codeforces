#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;

const int mod = 998244353;

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
        vector<int> a(n);
        vector<int> b(k);
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < k; ++i)
        {
            cin >> b[i];
            --b[i];
            b[i] = pos[b[i]];
        }
        reverse(b.begin(), b.end());
        map<int, int> used;
        used[-1] = 1;
        used[n] = 1;
        int ans = 1;
        for (auto el : b)
        {
            int cur = 2 - used[el - 1] - used[el + 1];
            ans *= cur;
            ans %= mod;
            used[el] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}