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

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b)
{
    if (!b)
        return 1;
    if (b % 2)
        return (a * binpow(a, b - 1)) % MOD;
    return binpow((a * a) % MOD, b / 2);
}

const int N = 700009;


vector<pair<int, int> > gr[N];



int p[N];
int sz[N];

int parent(int v)
{
    return (p[v] == v ? v : (p[v] = parent(p[v])));
}

bool union1(int a, int b)
{
    a = parent(a);
    b = parent(b);
    if (a == b)
        return 0;
    if (sz[a] < sz[b])
        swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return 1;
}

unordered_map<ll, int> q;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int m;
    cin >> m;
    ll k;
    cin >> k;
    q.rehash(500000);
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int cur = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (!q.count((c[x] ^ c[y])))
            q[(c[x] ^ c[y])] = cur++;
        gr[q[(c[x] ^ c[y])]].push_back(make_pair(x, y));
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < cur; i++)
    {
        ll curver = n;
     //   cout << endl << endl;
        for (int j = 0; j < gr[i].size(); j++)
        {
            int x = gr[i][j].first, y = gr[i][j].second;
            curver -= union1(x, y);
        }
        ans += binpow(2, curver);
        ans %= MOD;
        for (int j = 0; j < gr[i].size(); j++)
        {
            p[gr[i][j].first] = gr[i][j].first;
            p[gr[i][j].second] = gr[i][j].second;
           // used[gr[i][j].first] = 0;
           // used[gr[i][j].second] = 0;
            sz[gr[i][j].first] = 1;
            sz[gr[i][j].second] = 1;
        }
    }
    ll t = binpow(2, k) - (ll)cur;
    ans += (binpow(2, n) * t) % MOD;
    ans %= MOD;
    ans += MOD;
    cout << ans % MOD << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
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