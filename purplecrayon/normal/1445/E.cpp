#include "bits/stdc++.h"
using namespace std;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


struct DSU {
    int p[MAXN], sz[MAXN];
    void init(int n){ iota(p, p+n, 0); fill(sz, sz+n, 1); }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a, sz[a] += sz[b], sz[b] = 0;
    }
} d;

int n, m, k, a[MAXN], col[MAXN];
vector<int> adj[MAXN], groups[MAXK];
bool posCol[MAXK];

bool dfs(int c, bool cc){
    col[c] = cc; int good=1;
    for (auto nxt : adj[c]) if (a[nxt] == a[c]) {
        if (col[nxt] == -1) good &= dfs(nxt, cc^1);
        else good &= (col[nxt] == (cc^1));
    }
    return good;
}
vector<int> adj2[MAXN];
bool dfs2(int c, vector<int>& curCol, int x){
    curCol[c] = x;
    for (auto nxt : adj2[c]){
        if (curCol[nxt] == -1) if (!dfs2(nxt, curCol, x^1)) return false;
        if (curCol[nxt] != (x^1)) return false;
    }
    return true;
}
bool isBi(vector<pair<int, int>>& ed, int cn){
    for (int i = 0; i < cn; i++) adj2[i].clear();
    for (auto& it : ed) adj2[it.first].push_back(it.second), adj2[it.second].push_back(it.first);
    vector<int> curCol(cn, -1);
    for (int i = 0; i < cn; i++) if (curCol[i] == -1) if (!dfs2(i, curCol, 0)) return false;
    return true;
}
void read(int& a){
    scanf("%d", &a);
}
void solve(){
    read(n), read(m), read(k); d.init(n);
    for (int i = 0; i < n; i++) {
        read(a[i]), --a[i];
        groups[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++){
        int x, y; read(x), read(y), --x, --y;
        adj[x].push_back(y), adj[y].push_back(x);
        if (a[x] == a[y]) d.union_sets(x, y);
    }
    fill(col, col+n, -1); fill(posCol, posCol+k, 1);
    ll canCol=0;
    for (int i = 0; i < n; i++) if (col[i] == -1){
        posCol[a[i]] &= dfs(i, 0);
    }
    for (int i = 0; i < k; i++) canCol += posCol[i];
    ll ans=canCol*(canCol-1); vector<pair<int, int>> ed; map<pair<int, int>, int> comp; map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < k; i++) if (posCol[i]){
        mp.clear();
        for (auto it : groups[i]) for (auto nxt : adj[it]) if (posCol[a[nxt]] && a[nxt] != i) mp[a[nxt]].push_back({it, nxt});
        for (auto& j : mp){
            comp.clear();
            auto get = [&](int x){ return make_pair(d.find_set(x), col[x]); };
            ed.clear(); ed.reserve(sz(j.second));
            for (auto& it : j.second)  comp[get(it.first)]++, comp[get(it.second)]++;
            int cc=0; for (auto& it : comp) it.second=cc++;
            
            for (auto& it : j.second){
                ed.emplace_back(comp[get(it.first)], comp[get(it.second)]);
            }
            for (auto& it : comp) if (it.first.second && comp.count(make_pair(it.first.first, 0))) ed.emplace_back(it.second, comp[make_pair(it.first.first, 0)]);
            // for (auto it : ed) cout << i << ' ' << j.first << ' ' << it.first << ' ' << it.second << '\n';
            // cout << "ANS: " << i << ' ' << j.first << ' ' << isBi(ed, cc) << '\n';
            ans -= 1^isBi(ed, cc);
        }
    }
    assert(ans%2 == 0);
    cout << (ans/2) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}