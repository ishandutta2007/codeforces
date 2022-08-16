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

const int MOD = 1e9 + 7;

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

void solve()
{
    int n;
    cin >> n;

    int a[n];
    f(i, n) cin >> a[i];

    pair<int, pii> res = {0, {n, 0}};

    int l = 0;

    while (l < n)
    {
        while (l < n && a[l] == 0)
        {
            l++;
        }

        int r = l;

        while (r < n && a[r] != 0)
        {
            r++;
        }

        // find for [l , r - 1]
        int sgn = 0;

        for (int i = l; i < r; i++)
        {
            if (a[i] < 0)
            {
                sgn ^= 1;
            }
        }

        int ss = 0;

        for (int i = l; i < r; i++)
        {
            if (a[i] == 2 || a[i] == -2)
                ss++;
        }

        if (sgn == 0)
        {
            res = max(res, {ss, {l, n - r}});
        }
        else
        {
            int ss1 = ss;

            for (int i = l; i < r; i++)
            {
                if (a[i] == 2 || a[i] == -2)
                {
                    ss1--;
                }

                if (a[i] < 0)
                {
                    res = max(res, {ss1, {i + 1, n - r}});
                    break;
                }
            }

            int ss2 = ss;

            for (int i = r - 1; i >= l; i--)
            {
                if (a[i] == 2 || a[i] == -2)
                {
                    ss2--;
                }

                if (a[i] < 0)
                {
                    res = max(res, {ss2, {l, n - i}});
                    break;
                }
            }
        }

        l = r;
    }

    cout << res.S.F << ' ' << res.S.S << '\n';
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}