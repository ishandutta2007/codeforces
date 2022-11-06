#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
// #define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

class DSU
{
public:
    int *parent;
    int *par;
    int n;
    bool all_ok;
    stack<pii> roll1;
    stack<pii> roll2;
    DSU(int n) : n(n) { 
        parent = new int[n]; 
        all_ok = 1;
        par = new int[n]; 
        for (int i = 0; i < n; ++i) 
            par[i] = 0, parent[i] = -1; 
    };
    bool merge(int x, int y);
    bool merge2(int x, int y);
    void rollback() {
        // assert(!all_ok);
        while (!roll1.empty()) {
            auto top = roll1.top();
            roll1.pop();
            parent[top.fi] = top.se;
        }
        while (!roll2.empty()) {
            auto top = roll2.top();
            roll2.pop();
            par[top.fi] = top.se;
        }
    }
    int root(int x);
    int root2(int x);
};

int DSU::root(int x) {
    // assert(all_ok);
    if (parent[x] < 0) return x;
    int pp = root(parent[x]);
    par[x] = par[x] ^ par[parent[x]];
    parent[x] = pp; 
    return pp;
}

bool DSU::merge(int x, int y) {
    // assert(all_ok);
    int x_m = x, y_m = y;
    x = root(x);
    y = root(y);
    if (x == y) {
        if ((par[x_m] ^ par[y_m]) == 0) return false;
        return true;
    }
    if (parent[x] > parent[y]) swap(x, y), swap(x_m, y_m);
    if (parent[x] == parent[y]) parent[x]--;
    // parent[x] += parent[y];
    parent[y] = x;
    par[y] = par[x_m] ^ par[y_m] ^ 1;
    return true;
}

int DSU::root2(int x) {
    // assert(!all_ok);
    if (parent[x] < 0) return x;
    int pp = root2(parent[x]);
    roll1.push({x, parent[x]});
    roll2.push({x, par[x]});
    par[x] = par[x] ^ par[parent[x]];
    parent[x] = pp; 
    return pp;
}

bool DSU::merge2(int x, int y) {
    // assert(!all_ok);
    int x_m = x, y_m = y;
    x = root2(x);
    y = root2(y);
    if (x == y) {
        if ((par[x_m] ^ par[y_m]) == 0) return false;
        return true;
    }
    if (parent[x] > parent[y]) swap(x, y), swap(x_m, y_m);
    roll1.push(pii(y, parent[y]));
    roll1.push(pii(x, parent[x]));
    roll2.push(pii(y, par[y]));
    if (parent[x] == parent[y]) parent[x]--;
    // parent[x] += parent[y];
    parent[y] = x;
    par[y] = par[x_m] ^ par[y_m] ^ 1;
    return true;
}

const int N = 500005;
bool ok_gr[N];
int c[N];
map<pii, vector<pii>> mp;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int n; cin >> n;
    int m; cin >> m;
    long long k; cin >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    DSU d(n + 1);
    for (int i = 1; i <= k; ++i) ok_gr[i] = 1;
    for (int op = 0; op < m; ++op) {
        int u; cin >> u;
        int v; cin >> v;
        if (c[u] == c[v]) {
            bool ok = d.merge(u, v);
            if (!ok) ok_gr[c[u]] = false;
        } else {
            if (c[u] > c[v]) swap(u, v);
            mp[{c[u], c[v]}].pb({u, v}); 
        }
    }
    long long cnt = (k * (k - 1)) / 2ll;
    long long t1 = 0;
    for (int i = 1; i <= k; ++i) {
        if (!ok_gr[i]) {
            t1++;
        }
    }
    cnt -= (t1 * (k - t1) + (t1 * (t1 - 1ll)) / 2ll);
    for (int i = 1; i <= n; ++i)
        d.root(i);
    d.all_ok = 0;
    for (const auto &p : mp) {
        if (ok_gr[p.fi.fi] && ok_gr[p.fi.se]) {
            for (const auto &r : p.se) {
                if (!d.merge2(r.fi, r.se)) {
                    cnt--;
                    break;
                }
            }
        } 
        d.rollback();
    } 
    cout << cnt << '\n';
}