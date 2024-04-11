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
#include <iomanip>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

vector<vector<ll> > prod(vector<vector<ll> > a, vector<vector<ll> > b)
{
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            swap(b[i][j], b[j][i]);
    vector<vector<ll> > c = a;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < a.size(); k++)
                c[i][j] = (c[i][j] + a[i][k] * b[j][k]) % MOD;
        }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            swap(b[i][j], b[j][i]);

    return c;
}

vector<vector<ll> > binpow(vector<vector<ll> > a, ll b)
{
    if (b == 1)
        return a;
    if (b % 2)
        return prod(binpow(a, b - 1), a);
    return binpow(prod(a, a), b / 2);
}

int solve()
{
    ll n;
    int m;
    cin >> n >> m;
    if (n < m)
    {
        cout << 1 << endl;
        return 1;
    }
    if (n == m)
    {
        cout << 2 << endl;
        return 1;
    }
    if (n == m + 1)
    {
        cout << 3 << endl;
        return 1;
    }
    vector<vector<ll>> a(m, vector<ll>(m, 0));
    for (int i = 1; i < m; i++)
        a[i - 1][i] = 1;
    a[m - 1][0] = a[m - 1][m - 1] = 1;
    a = binpow(a, n - m );
    ll ans = 0;
  /*  for (int i = 0; i < m; i++)
        for (int j = 0; j < m - 1; j++)
            ans = (ans + a[i][j]) % MOD;
    for (int j = 0; j < m; j++)
        ans = (ans + 2LL * a[j][m - 1]) % MOD;*/
    for (int j = 0; j < m; j++)
        ans = (ans + a[m - 1][j]) % MOD;
    cout << (ans + a[m - 1][m - 1]) % MOD << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
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