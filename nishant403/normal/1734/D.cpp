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
    int n, k;
    cin >> n >> k;
    k--;

    int a[n];
    f(i, n) cin >> a[i];

    int cur_health = a[k];

    int l = k - 1;
    int r = k + 1;

    while (l >= 0 && r < n)
    {
        while (l > 0 && a[l] < 0 && a[l] + cur_health >= 0)
        {
            a[l - 1] += a[l];
            l--;
        }

        while (r < n - 1 && a[r] < 0 && a[r] + cur_health >= 0)
        {
            a[r + 1] += a[r];
            r++;
        }

        if (a[l] >= 0)
            cur_health += a[l], l--;
        else if (a[r] >= 0)
            cur_health += a[r], r++;
        else if (l == 0 && cur_health + a[l] >= 0)
            cur_health += a[l], l--;
        else if (r == n - 1 && cur_health + a[r] >= 0)
            cur_health += a[r], r++;
        else
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}