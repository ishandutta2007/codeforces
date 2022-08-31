#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e5 + 10;
const int BLK = 8e7 + 500;
const int OFF = 4e7 + 100;

int n;
int a[N];
int fre[BLK];

int b[N];

int max_fre = 0;

void add(int x)
{
    x += OFF;

    if (x >= 0 && x < BLK)
    {
        fre[x]++;
        max_fre = max(max_fre, fre[x]);
    }
}

void remove(int x)
{
    x += OFF;

    if (x >= 0 && x < BLK)
    {
        fre[x]--;
    }
}

int fix_difference(int d)
{
    max_fre = 0;
    f(i, n) add(a[i] - (i * d));

    int res = max_fre;

    f(i, n) remove(a[i] - (i * d));

    return n - res;
}

int fix_elem(int ind)
{
    max_fre = 0;

    int L = ind - 400;
    int R = ind + 400;

    L = max(L, 0);
    R = min(R, n - 1);

    for (int i = L; i <= R; i++)
    {
        if (i != ind)
        {
            int dif = a[i] - a[ind];

            int dis = (i - ind);

            if ((dif % dis) == 0)
            {
                add(dif / dis);
            }
        }
    }

    int res = max_fre + 1;

    for (int i = L; i <= R; i++)
    {
        if (i != ind)
        {
            int dif = a[i] - a[ind];

            int dis = (i - ind);

            if ((dif % dis) == 0)
            {
                remove(dif / dis);
            }
        }
    }

    return n - res;
}

void solve()
{
    cin >> n;
    f(i, n) cin >> a[i];

    // Case 1 : difference is <= sqrt(1e5)
    int res = n;

    for (int i = -400; i <= 400; i++)
        res = min(res, fix_difference(i));

    // Case 2 : difference is >= sqrt(1e5)
    // in this case , if an element a[i] is there in answer,
    // only elements from a[i - sqrt(1e5)] to a[i + sqrt(1e5)] can be there, as d >= 1e5

    // for every a[i] find maximum that can be there

    for (int i = 0; i < n; i++)
    {
        res = min(res, fix_elem(i));
    }

    cout << res << '\n';
}

signed main()
{
    fast;

    int t = 1;

    //    cin >> t;

    while (t--)

        solve();
}