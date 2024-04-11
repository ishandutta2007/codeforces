#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], deg[5*MAXN];
vector<pair<int, int>> ed; //{a, b} means that a comes before b
vector<int> adj[5*MAXN];

void bld(int v, int tl, int tr){
    // for (int i = tl; i <= tr; i++) ed.emplace_back(i, n+v);
    if (tl == tr){
        ed.emplace_back(tl, n+v);
    } else {
        int tm=(tl+tr)/2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
        ed.emplace_back(n+2*v, n+v), ed.emplace_back(n+2*v+1, n+v);
    }
}
void add(int v, int tl, int tr, int l, int r, int pos){ //pos > [l...r]
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r){
        ed.emplace_back(n+v, pos);
        return;
    }
    int tm=(tl+tr)/2;
    add(2*v, tl, tm, l, r, pos), add(2*v+1, tm+1, tr, l, r, pos);
}
void solve(){
    cin >> n;
    int cn=5*n;
    for (int i = 0; i < cn; i++) adj[i].clear(), deg[i] = 0;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] -= (a[i] != -1);
    bld(1, 0, n-1);
    for (int i = 0; i < n-1; i++) if (a[i] != -1) {
        add(1, 0, n-1, i+1, a[i]-1, i);
        if (a[i] < n) add(1, 0, n-1, i, i, a[i]);
    }
    for (auto& it : ed) 
        adj[it.first].push_back(it.second), adj[it.second].push_back(it.first), 
        deg[it.second]++;
    ed.clear();
    queue<int> q; for (int i = 0; i < cn; i++) if (!deg[i]) q.push(i);
    int csz=0;
    while (sz(q)){
        int c = q.front(); q.pop();
        if (c < n) a[c] = csz++;
        for (auto nxt : adj[c]){
            deg[nxt]--;
            if (!deg[nxt]) q.push(nxt);
        }
    }
    if (csz != n){ cout << "-1\n"; return; }
    for (int i = 0; i < n; i++) cout << (a[i]+1) << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}