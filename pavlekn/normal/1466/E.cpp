#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int mul(int a, int b)
{
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

int add(int a, int b)
{
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}

int dif(int a, int b)
{
    a %= mod;
    b %= mod;
    return ((a - b) % mod + mod) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> cnt(60);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 60; ++j)
            {
                if (a[i] & (1ll << j))
                {
                    ++cnt[j];
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < 60; ++j)
            {
                if (a[i] & (1ll << j))
                {
                    sum1 = add(sum1, mul((1ll << j), cnt[j]));
                    sum2 = add(sum2, mul((1ll << j), n));
                }
                else
                {
                    sum2 = add(sum2, mul((1ll << j), cnt[j]));
                }
            }
            ans = add(ans, mul(sum1, sum2));
        }
        cout << ans << endl;
    }
    return 0;
}