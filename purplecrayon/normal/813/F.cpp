#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, q, par[MAXN], sz[MAXN];
bool col[MAXN];
bool bip = 1;

int find_set(int v){ return v==par[v]?v:find_set(par[v]); }
int get_col(int v){ return v==par[v]?col[v]:col[v]^get_col(par[v]); }

bool ans[MAXN];
map<ar<int, 2>, int> mp;
vector<ar<int, 2>> t[4*MAXN];
void ae(int v, int tl, int tr, int l, int r, ar<int, 2> val) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        t[v].push_back(val);
        return;
    }
    int tm=(tl+tr)/2;
    ae(2*v, tl, tm, l, r, val), ae(2*v+1, tm+1, tr, l, r, val);
}
void dc(int v, int tl, int tr) {
    vector<ar<int, 5>> info(sz(t[v]));
    for (int c = 0; c < sz(t[v]); c++) {
        if (!bip){ info[c][0] = -1; continue; }

        int& a = t[v][c][0]; int& b = t[v][c][1];

        int pa = find_set(a), pb = find_set(b), ca = get_col(a), cb = get_col(b);
        info[c] = {pa, pb, ca, cb, -1};
        if (pa == pb) {
            if (ca == cb) {
                bip = 0;
            }
            info[c][4] = -1;
            continue;
        }

        if (sz[pa] < sz[pb]) swap(pa, pb), swap(ca, cb), swap(a, b);
        col[pb] ^= (ca == cb), par[pb] = pa, sz[pa] += sz[pb];

        info[c] = {pa, pb, ca, cb, ca == cb};
    }
    if (tl == tr) {
        ans[tl] = bip;
    } else {
        int tm=(tl+tr)/2;
        dc(2*v, tl, tm), dc(2*v+1, tm+1, tr);
    }
    for (int c = sz(t[v])-1; c >= 0; c--) {
        if (info[c][0] == -1) continue;

        auto [pa, pb, ca, cb, stat] = info[c];
        if (stat == -1) {
            bip = 1;
            continue;
        }

        sz[pa] -= sz[pb], par[pb] = pb, col[pb] ^= stat;
    }
}

void solve(){
    cin >> n >> q;
    for (int qt = 0; qt < q; qt++) {
        int a, b; cin >> a >> b, --a, --b;
        if (mp.count({a, b})) {
            ae(1, 0, q-1, mp[{a, b}], qt-1, {a, b});
            mp.erase({a, b});
        } else mp[{a, b}] = qt;
    }
    for (auto c : mp) ae(1, 0, q-1, c.second, q-1, c.first);

    iota(par, par+n, 0), fill(sz, sz+n, 1), fill(col, col+n, 0);
    dc(1, 0, q-1);
    for (int i = 0; i < q; i++) cout << (ans[i]?yes:no);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}