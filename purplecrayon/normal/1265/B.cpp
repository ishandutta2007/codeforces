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
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) cin >> a[i], --a[i], pos[a[i]] = i;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) l[i] = r[i] = pos[i];
    for (int i = 1; i < n; i++) l[i] = min(l[i], l[i-1]), r[i] = max(r[i], r[i-1]);
    for (int i = 0; i < n; i++) cout << (r[i]-l[i] == i);
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}