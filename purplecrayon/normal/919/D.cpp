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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e6, MAXB = 20, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, a[MAXN], sz[MAXN], dp[MAXN][ALP];
vector<int> adj[MAXN];

vector<int> top(){
    queue<int> q;
    for (int i = 0; i < n; i++) if (!sz[i]) q.push(i);
    vector<int> t;
    while (sz(q)){
        int c=q.front(); q.pop();
        t.push_back(c);
        for (auto nxt : adj[c]) {
            sz[nxt]--;
            if (sz[nxt] == 0) q.push(nxt);
        }
    }
    return t;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){ char c; cin >> c; a[i] = c-'a'; }
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), sz[b]++;
    }
    vector<int> t = top(); if (sz(t) != n) { cout << -1; return; }
    memset(dp, 0, sizeof(dp));
    for (int i = n-1; i >= 0; i--){
        int c = t[i];
        dp[c][a[c]] = 1;
        for (int j = 0; j < ALP; j++){
            for (auto nxt : adj[c]){
                dp[c][j] = max(dp[c][j], (a[c]==j)+dp[nxt][j]);
            }
        }
    }
    int ans=0;
    for (int i = 0; i < n; i++) for (int j = 0; j < ALP; j++) ans = max(ans, dp[i][j]);
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}