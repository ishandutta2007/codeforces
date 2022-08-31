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

int res;
int n;
string s;

void recur(int l, int r)
{
    if (l == r)
    {
        return;
    }

    int mid = (l + r) / 2;

    recur(l, mid);
    recur(mid + 1, r);

    vector<int> sums[3];
    int cur_sum = 0;

    for (int j = mid + 1; j <= r; j++)
    {
        if (s[j] == '-')
            cur_sum--;
        else
            cur_sum++;

        sums[((cur_sum + (3 * n)) % 3)].pb(cur_sum);
    }

    f(i, 3) sort(all(sums[i]));

    cur_sum = 0;

    for (int j = mid; j >= l; j--)
    {
        if (s[j] == '-')
            cur_sum--;
        else
            cur_sum++;

        int find_in = (3 * n - cur_sum) % 3;

        res += upper_bound(all(sums[find_in]), -cur_sum) - sums[find_in].begin();
    }
}

void solve()
{
    cin >> n >> s;
    res = 0;

    recur(0, n - 1);

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