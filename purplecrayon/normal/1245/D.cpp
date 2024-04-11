#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n;
pair<ll, ll> a[MAXN];
ll cb[MAXN], k[MAXN];
int bldb[MAXN];
vector<int> adj[MAXN];

ll dist(int i, int j){ return abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second); }
ll cost(int i, int j){ return (k[i]+k[j])*dist(i, j); }
ll rec(vector<int>& cur){
    if (sz(cur)==1) return cb[cur[0]];
    int bld=-1;
    for (auto it : cur) if (bld == -1 || cb[bld] > cb[it]) bld = it;
    assert(bld!=-1); cur.erase(find(cur.begin(), cur.end(), bld));
    for (auto it : cur) if (cb[it] > cost(bld, it)) cb[it] = cost(bld, it), bldb[it] = bld;
    return cb[bld]+rec(cur);
}
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; i++) cin >> cb[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<int> cur(n); iota(cur.begin(), cur.end(), 0);
    memset(bldb, -1, sizeof(bldb));
    cout << rec(cur) << '\n';
    vector<int> v; vector<pair<int, int>> e;
    for (int i = 0; i < n; i++) {
        if (bldb[i] == -1) v.push_back(i);
        else e.push_back({i, bldb[i]});
    }
    cout << sz(v) << '\n';
    for (auto it : v) cout << (it+1) << ' ';
    cout << '\n' << sz(e) << '\n';
    for (auto it : e) cout << (it.first+1) << ' ' << (it.second+1) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}