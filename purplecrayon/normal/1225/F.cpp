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

int n, par[MAXN], md[MAXN], st[MAXN], tt=0;
vector<int> adj[MAXN];

int dfs1(int c=0) {
    md[c] = 1;
    for (auto nxt : adj[c]) md[c] = max(md[c], dfs1(nxt)+1);
    return md[c];
}
void dfs2(int c=0) {
    sort(adj[c].begin(), adj[c].end(), [&](int i, int j){ return md[i] < md[j]; }); 
    st[tt++] = c;
    for (auto nxt : adj[c]) dfs2(nxt);
}
void solve(){
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> par[i], adj[par[i]].push_back(i);
    }
    dfs1(), dfs2();
    vector<int> ans; ans.reserve(n);
    for (int i = 1; i < n; i++) {
        for (int a=st[i], b=st[i-1]; b != par[a]; b = par[b]) ans.push_back(a);
    }
    for (int i = 0; i < n; i++) cout << st[i] << ' '; cout << '\n';
    cout << sz(ans) << '\n';
    for (int c : ans) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}