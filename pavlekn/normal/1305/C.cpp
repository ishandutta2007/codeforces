#include <bits/stdc++.h>

using namespace std;

#define int long long

int pow(int a, int n, int mod)
{
    if (n == 0)
    {
        return 1ll;
    }
    if (n == 1)
    {
        return a % mod;
    }
    int res = pow(a, n / 2ll, mod);
    res *= res;
    res %= mod;
    if (n % 2ll)
    {
        res *= a;
    }
    res %= mod;
    return res;
}

const int MAXM = 1003;

int cnt[MAXM];
int cnt2[MAXM];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] %= m;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= a[i]; ++j)
        {
            cnt2[a[i] - j] += cnt[j];
        }
        for (int j = a[i]; j < m; ++j)
        {
            cnt2[a[i] - j + m] += cnt[j];
        }
        ++cnt[a[i]];
    }
    for (int i = 0; i < m; ++i)
    {
        ans *= pow(i, cnt2[i], m);
        ans %= m;
    }
    cout << ans << endl;
    return 0;
}