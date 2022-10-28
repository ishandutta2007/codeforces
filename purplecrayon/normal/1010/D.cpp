#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

int eval(int a, int b, string op) {
    if (op == "XOR") return a^b;
    if (op == "OR") return a|b;
    if (op == "AND") return a&b;
    assert(false);
    return -1;
}

int n, a[MAXN], ans[MAXN];
ar<int, 2> adj[MAXN];
string type[MAXN];

int calc(int c) {
    if (type[c] == "IN") return a[c];
    if (type[c] == "NOT") {
        auto v = adj[c][0];
        return a[v]^1;
    }
    auto u = adj[c][0], v = adj[c][1];
    return eval(a[u], a[v], type[c]);
}
void dfs1(int c) {
    for (auto nxt : adj[c]) if (nxt != -1) dfs1(nxt);
    a[c] = calc(c);
}
void dfs2(int c, int p) {
    if (p == -1) ans[c] = 1;
    else {
        a[c] ^= 1;
        ans[c] = (a[p] ^ calc(p)) && ans[p];
        a[c] ^= 1;
    }
    for (auto nxt : adj[c]) if (nxt != -1) dfs2(nxt, c);
}
void solve(){
    cin >> n;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> type[i];
        adj[i] = {-1, -1};
        if (type[i] == "IN") {
            int x; cin >> x;
            a[i] = x;
        } else if (type[i] == "NOT") {
            int a; cin >> a, --a;
            adj[i] = {a, -1};
        } else {
            int a, b; cin >> a >> b, --a, --b;
            adj[i] = {a, b};
        }
    }
    dfs1(0), dfs2(0, -1);
    for (int i = 0; i < n; i++) if (type[i] == "IN") cout << (a[0]^ans[i]);
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}