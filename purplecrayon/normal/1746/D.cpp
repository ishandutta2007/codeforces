#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

int n, K;
ll a[N];
vector<int> adj[N];

ar<ll, 2> dfs(int c, int k) {
    int cnt = sz(adj[c]);

    ll base = 0;
    vector<ll> extra;
    for (auto nxt : adj[c]) {
        auto [me_one, me_two] = dfs(nxt, k / cnt);
        base += me_one;
        extra.push_back(me_two - me_one);
    }
    sort(extra.rbegin(), extra.rend());
    auto calc = [&](int use) {
        ll ans = base;
        for (int i = 0; i < use; i++) ans += max(0LL, extra[i]);
        return ans;
    };

    return {(cnt ? calc(k % cnt) : 0) + a[c] * k, (cnt ? calc(k % cnt + 1) : 0) + a[c] * (k + 1)};
}
void solve() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int p; cin >> p, --p;
        adj[p].push_back(i);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(0, K)[0] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}