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

/*struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n) { iota(p, p+n, 0); fill(sz, sz+n, 1); }
    void make_set(int v){ p[v]=v, sz[v]=1; }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b]=a, sz[a]+=sz[b], sz[b]=0;
    }
} d;*/

void solve(){
    int n; cin >> n; 
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<pair<int, int>> cnt;
    for (auto it : a){
        if (cnt.size() && cnt.back().first == it) cnt.back().second++;
        else cnt.push_back({it, 1});
    }
    if (sz(cnt)<3) { cout << "0 0 0\n"; return; }
    int g=cnt[0].second, s=0; int ptr=1;
    while (ptr<sz(cnt) && s<=g) s += cnt[ptr].second, ptr++;
    if (s <= g) { cout << "0 0 0\n"; return; }
    int b=0;
    while (ptr<sz(cnt) && b <= g) b += cnt[ptr].second, ptr++;
    if (b <= g) { cout << "0 0 0\n"; return; }
    while (ptr<sz(cnt) && g+s+b+cnt[ptr].second<=n/2) b+=cnt[ptr].second, ptr++;
    if (g+s+b>n/2){ cout << "0 0 0\n"; return; }
    cout << g << ' ' << s << ' ' << b << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}