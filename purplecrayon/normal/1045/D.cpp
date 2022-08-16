#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

typedef float ld;

int n, par[MAXN];
ld a[MAXN], ans = 0, ch[MAXN];
vector<int> adj[MAXN];

void dfs(int c=0, int p=-1) {
    par[c] = p;
    for (auto nxt : adj[c]) if (nxt != p) {
        ch[c] += a[nxt];
        dfs(nxt, c);
    }
    ans += a[c] - a[c]*ch[c];
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = ld(1)-a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs();

    int q; cin >> q;
    cout << fixed << setprecision(8);

    while (q--) {
        int c; cin >> c;
        ld x; cin >> x, x = ld(1)-x;

        ans -= a[c], ans += x;
        ans += a[c]*ch[c], ans -= x*ch[c];
        if (c) {
            ans += a[par[c]]*ch[par[c]];
            ch[par[c]] -= a[c], ch[par[c]] += x;
            ans -= a[par[c]]*ch[par[c]];
        }

        a[c] = x;

        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}