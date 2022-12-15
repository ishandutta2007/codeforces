#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);

    const int mod = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector <long long> a(n);
        for (long long &x : a)
            cin >> x;

        vector <int> cnt(60, 0);
        for (long long x : a)
        for (int i = 0; i < 60; i++)
        {
            if ((x >> i) & 1)
                cnt[i]++;
        }

        long long ans = 0;
        for (long long val : a)
        {
            ans += (long long) n * n % mod * (val % mod) % mod * (val % mod);

            long long x = 0;
            long long y = 0;

            for (int i = 0; i < 60; i++)
            {
                int b = (val >> i) & 1;
                if (b == 1)
                    y += ((1LL << i) % mod)* (n - cnt[i]);
                else
                    x += ((1LL << i) % mod) * cnt[i];
            }
            x %= mod;
            y %= mod;

            ans += (val % mod) * n % mod * (x - y);
            ans -= x * y;

            ans = (ans % mod + mod) % mod;
        }
        cout << ans << "\n";

    }

    return 0;
}