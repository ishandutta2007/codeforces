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

    int all_same = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            all_same = 0;
        }
    }

    if (all_same)
    {
        cout << "Yes\n";
        return;
    }

    for (int last_digit = 0; last_digit <= 8; last_digit += 2)
    {
        int b[n];

        int flag = 1;

        f(i, n)
        {
            b[i] = a[i];

            int ctr = 0;

            while (b[i] % 10 != last_digit)
            {
                if (ctr > 10)
                    break;

                b[i] += (b[i] % 10);

                ctr++;
            }

            if (b[i] % 10 != last_digit)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 0)
            continue;

        if (last_digit == 0)
        {
            all_same = 1;

            f(j, n) if (b[j] != b[0]) all_same = 0;

            if (all_same)
            {
                cout << "Yes\n";
                return;
            }
        }
        else
        {
            int mod = (b[0] / 10) % 2;

            all_same = 1;

            f(j, n) if (mod != ((b[j] / 10) % 2))
            {
                all_same = 0;
            }

            if (all_same)
            {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

signed main()
{
    fast;

    int t = 1;

    cin >> t;

    while (t--)

        solve();
}