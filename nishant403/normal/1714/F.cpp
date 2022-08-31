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
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    int sum = (d12 + d23 + d31);

    if (sum % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    sum /= 2;

    if (d12 > sum || d23 > sum || d31 > sum)
    {
        cout << "NO\n";
        return;
    }

    vector<pii> edges;

    if (d12 == d23 + d31)
    {
        int ctr = n;
        int last = 1;

        f(i, d31 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 3});

        last = 3;

        f(i, d23 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 2});
        last = 2;

        if (ctr < 3)
        {
            cout << "NO\n";
            return;
        }

        while (ctr > 3)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }
    }
    else if (d23 == d12 + d31)
    {
        int ctr = n;
        int last = 2;

        f(i, d12 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 1});
        last = 1;

        f(i, d31 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 3});
        last = 3;

        if (ctr < 3)
        {
            cout << "NO\n";
            return;
        }
        while (ctr > 3)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }
    }
    else if (d31 == d12 + d23)
    {
        int ctr = n;
        int last = 1;

        f(i, d12 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 2});
        last = 2;

        f(i, d23 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 3});
        last = 3;

        if (ctr < 3)
        {
            cout << "NO\n";
            return;
        }
        while (ctr > 3)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }
    }
    else
    {

        int d14 = sum - d23;
        int d24 = sum - d31;
        int d34 = sum - d12;

        int ctr = n;
        int last = 4;

        f(i, d14 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 1});

        last = 4;

        f(i, d24 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 2});

        last = 4;

        f(i, d34 - 1)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }

        edges.push_back({last, 3});

        last = 4;

        if (ctr < 4)
        {
            cout << "NO\n";
            return;
        }
        while (ctr > 4)
        {
            edges.push_back({last, ctr});
            last = ctr;
            ctr--;
        }
    }

    cout << "YES\n";

    for (auto x : edges)
    {
        cout << x.first << ' ' << x.second << '\n';
    }
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}