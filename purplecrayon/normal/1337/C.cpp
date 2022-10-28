#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int n, k;
vector<int> sub, adj[MAXN];

int dfs(int c=0, int p=-1, int d=1){
    int s=1;
    for (auto nxt : adj[c]) if (nxt != p) s += dfs(nxt, c, d+1);
    sub.push_back(s-d); return s;
}

void solve(){
    cin >> n >> k; k = n-k;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(); sort(sub.begin(), sub.end());
    // for (auto it : sub) cout << it << " ";
    // cout << "\n";
    ll ans = 0;
    for (int i = n-1; n-i <= k; i--){
        ans += sub[i];
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}