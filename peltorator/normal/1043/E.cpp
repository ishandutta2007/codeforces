#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
#include <random>

#define sz(a) (int)((a).size())
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

vector<ll> l, r, x, y;

int solve()
{
    int n, m;
    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<pair<ll, int> > q(n);
    for (int i = 0; i < n; i++)
        q[i] = {x[i] - y[i], i};
    sort(q.rbegin(), q.rend());
    vector<ll> ans(n, 0);
    ll sum = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++)
        sum2 += x[i];
    for (int i = 0; i < n; i++)
    {
        int j = q[i].second;
        sum2 -= x[j];
        ans[j] = (ll)i * x[j] + (ll)(n - i - 1) * y[j] + sum + sum2;
        sum += y[j];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (x[a] + y[b] < x[b] + y[a])
        {
            ans[a] -= x[a] + y[b];
            ans[b] -= y[b] + x[a];
        }
        else
        {
            ans[a] -= y[a] + x[b];
            ans[b] -= x[b] + y[a];
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}