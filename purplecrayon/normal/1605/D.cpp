#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, col[MAXN];
vector<int> adj[MAXN];

void dfs(int c, int p, int b) {
    col[c] = b;
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c, b^1);
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(0, -1, 0);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += col[i];

    if (sum > n - sum) {
        for (int i = 0; i < n; i++) col[i] ^= 1;
        sum = n - sum;
    }
    vector<int> one, two;
    for (int i = 1; i <= n; i++) {
        int hsb = 31 - __builtin_clz(i);
        if ((sum >> hsb) & 1) {
            one.push_back(i);
        } else {
            two.push_back(i);
        }
    }
    assert(sz(one) == sum);
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        if (col[i]) {
            cout << one[p1++] << ' ';
        } else {
            cout << two[p2++] << ' ';
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}