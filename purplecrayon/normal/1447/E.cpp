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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 31, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = MAXL*MAXN, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
    int cc=0;
    vector<int> p, sz;
    void init(int n){ p.assign(n, 0), sz.assign(n, 1); iota(p.begin(), p.end(), 0); cc=n; }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    bool union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b]=a, sz[a]+=sz[b], sz[b]=0;
        cc--;
        return true;
    }
} d;

int n, nxt[MAXA][2], cnt[MAXA], m=1;
ll a[MAXN];

int dfs(int c){
    if (nxt[c][0] != -1 && nxt[c][1] != -1){
        //have to remove everything except 1
        return min(dfs(nxt[c][1])+cnt[nxt[c][0]]-1, dfs(nxt[c][0])+cnt[nxt[c][1]]-1);
    }
    if (nxt[c][0] != -1) return dfs(nxt[c][0]);
    if (nxt[c][1] != -1) return dfs(nxt[c][1]);
    return 0;
}
void solve(){
    cin >> n; memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int c=0;
        for (ll j = MAXL-1; j >= 0; j--){
            if (nxt[c][a[i]>>j&1] == -1) nxt[c][a[i]>>j&1]=m++;
            c = nxt[c][a[i]>>j&1];
            cnt[c]++;
        }
    }
    cout << dfs(0) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}