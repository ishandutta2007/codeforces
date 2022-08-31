#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;
const int A = 26;

int n, nxt[N][A], m = 0;
bool leaf[N];
vector<int> use[N];

void dfs(int c, int d) {
    if (leaf[c]) use[c].push_back(d);
    for (int j = 0; j < 26; j++) if (nxt[c][j] != -1) {
        dfs(nxt[c][j], d + 1);
        for (int x : use[nxt[c][j]]) use[c].push_back(x);
        use[nxt[c][j]].clear();
    }
    if (c && !leaf[c]) {
        assert(sz(use[c]));
        use[c].erase(std::max_element(use[c].begin(), use[c].end()));
        use[c].push_back(d);
    }
}
void solve() {
    cin >> n;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int c = 0;
        for (char x : s) {
            if (nxt[c][x - 'a'] == -1) nxt[c][x - 'a'] = ++m;
            c = nxt[c][x - 'a'];
        }
        leaf[c] = 1;
    }
    dfs(0, 0);
    int ans = 0;
    for (int x : use[0]) ans += x;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}