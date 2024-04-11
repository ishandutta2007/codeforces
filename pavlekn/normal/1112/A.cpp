#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 2e18;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    vector<int> s(n);
    vector<int> c(k);
    vector<int> mx(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i)
    {
        mx[s[i] - 1] = max(mx[s[i] - 1], p[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        if (p[c[i] - 1] < mx[s[c[i] - 1] - 1])
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}