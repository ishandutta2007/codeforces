#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int modpow(int b, long long e)
{
    int ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (int) (((long long) ans * b) % MOD);
        e >>= 1;
        b = (int) (((long long) b * b) % MOD);
    }
    return ans;
}

int main()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    if (n % 2 != 0 && m % 2 != 0)
    {
        cout << modpow(r - l + 1, (long long) n * m) << endl;
    }
    else
    {
        int even, odd;
        even = odd = (r - l + 1) / 2;
        if ((r - l + 1) % 2 != 0)
        {
            if (r % 2 == 0)
                even++;
            else
                odd++;
        }
        int ans = modpow(odd + even, (long long) n * m);
        ans = ans + modpow(odd - even, (long long) n * m);
        if (ans >= MOD)
            ans -= MOD;
        ans = (int) (((long long) ans * (MOD / 2 + 1)) % MOD);
        cout << ans << endl;
    }
    return 0;
}