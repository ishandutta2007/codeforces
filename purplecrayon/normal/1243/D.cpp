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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const ll INF = 1e18+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
    int p[MAXN], sz[MAXN], nm=0;
    void init(int n){ fill(sz, sz+n, 1); iota(p, p+n, 0); nm=n; }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a, sz[a] += sz[b], nm--;
    }
} d;

set<int> adj[MAXN];

const int NMADD=2;
void solve(){
    //answer is the number of connected components using only zero edges (minus 1)
    //connect each node to the mex of its adj list
    int n, m; cin >> n >> m; d.init(n);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].insert(b), adj[b].insert(a);
    }
    for (int i = 0; i < n; i++){
        int c=i;
        for (int j = 0; j < NMADD; j++){
            c++;
            while (adj[i].count(c)) c++;
            if (c < n) d.union_sets(i, c);
        }
        c=i;
        for (int j = 0; j < NMADD; j++){
            c--;
            while (adj[i].count(c)) c--;
            if (c >= 0) d.union_sets(i, c);
        }
    }
    cout << (d.nm-1);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}