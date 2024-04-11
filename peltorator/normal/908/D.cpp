#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

typedef long long ll;
typedef double ld;

bool solve();

ll time()
{
    return (ll)clock() * 1000LL / CLOCKS_PER_SEC;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t = 2;
#ifdef ONLINE_JUDGE
    t = 1;
#endif
    while (t--)
        solve();
#ifndef ONLINE_JUDGE
	cerr << "time: " << time() << " ms" << endl;
#endif
    return 0;
}

const ll MOD = 1e9 + 7;

ll binpow(ll x, ll y)
{
    if (!y)
        return 1;
    if (y & 1)
        return (x * binpow(x, y - 1)) % MOD;
    return binpow((x * x) % MOD, y / 2);
}

ll revers(ll x)
{
    return binpow(x, MOD - 2);
}

const int N = 1005;

ll dp[N][N];
ll pasum[N];
ll paksum[N];

bool solve()
{
    ll k, pa, pb;
    cin >> k >> pa >> pb;
    ll pab = revers(pa + pb);
    pa = (pa * pab) % MOD;
    pb = (pb * pab) % MOD;
    pasum[0] = 1;
    for (int i = 1; i < N; i++)
        pasum[i] = (pasum[i - 1] + binpow(pa, i)) % MOD;
    for (ll i = 1; i < N; i++)
        paksum[i] = (paksum[i - 1] + i * binpow(pa, i)) % MOD;
    for (int i = 0; i < N; i++)
        dp[1][i] = binpow(pb, i) % MOD;
    for (int i = 2; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = (dp[i - 1][j] * pa) % MOD;
            if (j >= i)
                dp[i][j] = (dp[i][j] + dp[i][j - i] * pb) % MOD;
        }
    ll ans = 0;
    for (ll i = 1; i < N; i++)
        for (ll j = 0; j < N; j++)
            if (i + j < k)
            {
                ll sum1 = revers(1 - pa);
                ll sum2 = (sum1 * sum1 % MOD) * pa % MOD;
                if (k > 2 * i + j)
                {
                    sum1 -= pasum[k - 2 * i - j - 1];
                    sum2 -= paksum[k - 2 * i - j - 1];
                }
                sum1 = (((sum1 * dp[i][j] % MOD) * pb % MOD) * pb % MOD) * (2 * i + j) % MOD;
                sum2 = ((sum2 * dp[i][j] % MOD) * pb % MOD) * pb % MOD;
               // cout << i << " " << j << " "  << sum1 << " " << sum2 << endl;
                ans = (ans + sum1 + sum2) % MOD;
            }
    ll sum = revers(1 - pa);
    sum = ((sum * sum) % MOD * pa) % MOD;
    sum -= paksum[k - 1];
    sum = (sum * pb % MOD) * revers(pa) % MOD;
    ans += sum;
  //  cout << "ans: ";
    cout << (ans % MOD + MOD) % MOD << endl;
    return 1;
}