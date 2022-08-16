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

    int a[2][n];
    f(i, 2) f(j, n) cin >> a[i][j];

    int res = 1e18;

    vector<vi> suf(2, vi(n + 1, 0));

    f(i, 2) f(j, n)
    {
        suf[i][j] = max(suf[i][j], a[i][j] + n + n - j);
        suf[1 - i][j] = max(suf[1 - i][j], a[i][j] + j + 1);
    }

    for (int j = n - 2; j >= 0; j--)
    {
        f(i, 2)
        {
            suf[i][j] = max(suf[i][j], suf[i][j + 1]);
        }
    }

    int cur_time = 0;

    f(j, n)
    {
        f(i, 2)
        {
            int ii = i;

            if (j % 2 == 1)
            {
                ii = 1 - i;
            }

            int cur_cell = a[ii][j];

            cur_time = max(cur_time, cur_cell) + 1;

            if (ii == 0 && j == 0)
                cur_time = 0;

            int cells_left = (n - j - 1) * 2 + (1 - i);

            int best_time = cur_time + cells_left;

            int col_covered = j + 1 - (i == 0);

            best_time = max(best_time, suf[ii][j + 1] - col_covered);

            if (i == 0)
            {
                best_time = max(best_time, a[ii ^ 1][j] + 1);
            }

            res = min(res, best_time);
        }
    }

    cout << res << '\n';
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}