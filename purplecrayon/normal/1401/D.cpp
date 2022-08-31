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

int n, m;
ll sub[MAXN];
vector<ll> pf, amt;
vector<int> adj[MAXN];

int dfs(int c=0, int p=-1){
    sub[c] = 1;
    for (auto nxt : adj[c]) if (nxt != p){
        sub[c] += dfs(nxt, c);
    }
    if (c) amt.push_back((sub[c])*(n-sub[c]));
    return sub[c];
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    cin >> m; pf.clear(); amt.clear();
    for (int i = 0; i < m; i++){
        int a; cin >> a;
        pf.push_back(a);
    }
    sort(pf.begin(), pf.end());
    while (sz(pf) > n-1){
        ll a = pf.back(); pf.pop_back();
        ll b = pf.back(); pf.pop_back();
        pf.push_back(a*b%MOD);
    }
    reverse(pf.begin(), pf.end());
    while (sz(pf) < n-1){
        pf.push_back(1ll);
    }
    reverse(pf.begin(), pf.end());
    // for (auto it : pf) cout << it << " ";
    // cout << "\n";
    dfs(); sort(amt.begin(), amt.end());
    assert(sz(pf)==n-1 && sz(amt)==n-1);
    ll ans = 0;
    for (int i = sz(pf)-1; i >= 0; i--) ans += (pf[i]*amt[i])%MOD, ans%=MOD;
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}