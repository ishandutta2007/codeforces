#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;

const int N = 212345;
const int INF = 1e9 + 7;

int p[N];
ll s[N];

int findp(int v)
{
    if (p[v] == v)
        return v;
    return (p[v] = findp(p[v]));
}

void unions(int v, int u)
{
    v = findp(v);
    u = findp(u);
    if (s[v] < s[u])
        swap(v, u);
    s[v] += s[u];
    p[u] = v;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
        p[i] = i, s[i] = 1;
    int m;
    cin >> m;
    vector<pair<int, pair<int, int> > > q;
    for (int i = 1; i < n; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        q.push_back({w, {v, u}});
    }
    for (int i = 0; i < m; i++)
    {
        int z;
        cin >> z;
        q.push_back({z, {INF, i}});
    }
    sort(q.begin(), q.end());
    vector<ll> ans(m);
    ll curans = 0;
    for (auto it : q)
    {
        int v = it.second.first,  u = it.second.second;
        if (v == INF)
        {
            ans[u] = curans;
        }
        else
        {
            v = findp(v);
            u = findp(u);
            if (v != u)
                curans += s[v] * s[u];
            unions(v, u);
        }
    }
    for (ll i : ans)
        cout << i << ' ';
    cout << endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}