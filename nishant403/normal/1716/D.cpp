#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define int long long
#define pb push_back
#define S second
#define F first
#define f(i, n) for (int i = 0; i < n; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define precise(x) fixed << setprecision(x)

const int MOD = 998244353;

int mod_pow(int a, int b, int M = MOD)
{
    if (a == 0)
        return 0;
    b %= (M - 1); // M must be prime here

    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res;
}

const int N = 2e5 + 10;

int res[N];
int cur[N];
int nex[N];

void solve()
{
    int n, k;
    cin >> n >> k;

    cur[0] = 1;

    int mn_val = 0;

    for (int i = k; i <= k + 640; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nex[j] = 0;
        }

        for (int j = i; j <= n; j++)
        {
            nex[j] += cur[j - i] + nex[j - i];

            if (nex[j] >= MOD)
                nex[j] -= MOD;
        }

        for (int j = 0; j <= n; j++)
        {
            cur[j] = nex[j];
            res[j] += cur[j];
        }

        mn_val += i;
    }

    for (int i = 1; i <= n; i++)
    {
        res[i] %= MOD;
        cout << res[i] << ' ';
    }
}

signed main()
{
    fast;

    int t = 1;

    //    cin >> t;

    while (t--)

        solve();
}