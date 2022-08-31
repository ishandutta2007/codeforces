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
const int MAXN = 1e5+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

ll po(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n){ iota(p, p+n, 0); fill(sz, sz+n, 1); }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b]=a, sz[a]+=sz[b], sz[b]=0;
    }
} d;

void solve(){
    int n, k; cin >> n >> k; d.init(n);
    for (int i = 0; i < n-1; i++){
        int a, b, c; cin >> a >> b >> c, --a, --b;
        if (!c) d.union_sets(a, b);
    }
    ll ans=po(n, k);
    for (int i = 0; i < n; i++) if (d.p[i] == i) {
        ans = (ans-po(d.sz[i], k)+MOD)%MOD;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}