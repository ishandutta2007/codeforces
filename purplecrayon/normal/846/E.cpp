#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n;
ll a[MAXN];
pair<int, ll> par[MAXN];
vector<pair<int, ll>> adj[MAXN];

void dfs(int c) {
    for (auto [nxt, w] : adj[c]) {
        dfs(nxt);
        assert(a[nxt] >= 0);
        a[c] += a[nxt];
    }
    auto [p, w] = par[c];
    if (c && a[c] < 0) {
        ll need = -a[c];
        if ((long double) a[p] - (long double) w * (long double) need < LLONG_MIN) {
            cout << "NO\n";
            exit(0);
        }
        a[p] -= w*need;
        a[c] += need;
    }
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] -= x;
    }
    for (int i = 1; i < n; i++) {
        int p; ll x; cin >> p >> x, --p;
        adj[p].emplace_back(i, x);
        par[i] = {p, x};
    }
    dfs(0);
    cout << (a[0] >= 0 ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}