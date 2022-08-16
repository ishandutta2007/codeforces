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
    string t;
    cin >> t;

    int n;
    cin >> n;

    string s[n];

    f(i, n) cin >> s[i];

    int cur_cover = 0;

    int len = t.length();

    vector<pii> res;

    while (cur_cover < len)
    {
        // try to increase cur_cover as much as posssible
        int max_inc = -1;
        pair<int, int> take;

        f(i, n)
        {
            // check how much s[i] and t can match, which start at cur_cover or before it
            // and its end is at cur_cover or after it

            for (int start = 0; start <= cur_cover; start++)
            {
                int end = start + (int)s[i].length() - 1;

                if (end >= (int)t.length())
                    continue;

                if (end < cur_cover)
                    continue;

                // check if t[start ... end] match with s[i]

                int match = 1;

                for (int j = 0; j < s[i].length(); j++)
                {
                    if (s[i][j] != t[start + j])
                    {
                        match = 0;
                        break;
                    }
                }

                if (match)
                {
                    int cur_inc = end - cur_cover + 1;

                    if (max_inc < cur_inc)
                    {
                        max_inc = cur_inc;
                        take = {i, start};
                    }
                }
            }
        }

        if (max_inc == -1)
        {
            cout << -1 << '\n';
            return;
        }

        res.push_back(take);
        cur_cover = (int)take.second + (int)s[take.first].length();
    }

    cout << res.size() << '\n';

    for (auto x : res)
    {
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
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