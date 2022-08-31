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
const int MAXN = 1e4+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 11, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int c){
    vis[c]=1;
    for (auto nxt : adj[c]) if (!vis[nxt]) dfs(nxt);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a, --a;
        adj[i].push_back(a), adj[a].push_back(i);
    }
    int ans=0; memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i), ans++;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}