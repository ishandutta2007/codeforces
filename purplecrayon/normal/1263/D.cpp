#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e3+10, MAXM = 3e3+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll LINF = 1e18+10;

struct DSU {
    int nm;
    vector<int> p, sz;
    void init(int n){ p.assign(n, 0); iota(p.begin(), p.end(), 0); sz.assign(n, 1); nm=n; }
    int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
    void union_sets(int a, int b){
        if ((a=find_set(a))==(b=find_set(b))) return;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a, sz[a] += sz[b], sz[b] = 0; nm--;
    }
} d;
void solve(){
    int n; cin >> n; d.init(n);
    map<char, int> lst;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (auto c : s) if (lst.count(c)) d.union_sets(i, lst[c]);
        for (auto c : s) lst[c] = i;
    }
    cout << d.nm << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}