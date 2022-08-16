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

const int N = 50;

int res[N];

int sum(int num)
{
    int res = 0;

    while (num > 0)
    {
        res += (num % 10);
        num /= 10;
    }

    return res;
}

void go(int num)
{
    int ss = sum(num);

    if (ss < N)
    {
        res[ss] = min(res[ss], num);
    }

    int last_dg = (num % 10);

    for (int i = last_dg + 1; i <= 9; i++)
    {
        go((num * 10) + i);
    }
}

void pre()
{
    f(i, N) res[i] = 1e12;

    // take number from 1
    for (int i = 1; i <= 9; i++)
        go(i);
}

void solve()
{
    int n;
    cin >> n;
    cout << res[n] << '\n';
}

signed main()
{
    pre();

    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}