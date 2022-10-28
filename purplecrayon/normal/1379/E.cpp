#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

bool can(int n, int k) {
    if (n % 2 == 0) return 0;
    if (n == 9 && k == 2) return 0;
    if (__builtin_popcount(n + 1) == 1 && k <= 1) return !k;
    return 0 < k && k < n / 2;
}
int cur_node = 1;
void dfs(int n, int k, int par) {
    cout << par << ' ';
    int c = cur_node++;
    if (n == 1) return;
    // cerr << n << ' ' << k << ' ' << par << ' ' << c << endl;
    for (int L = 1; L < n; L = 2 * L + 1) { // size of left subtree
        int R = n - L - 1;
        int new_k = k;
        if (min(L, R) * 2 < max(L, R)) {
            new_k--;
        }
        // cerr << L << ' ' << R << ' ' << new_k << endl;
        if (can(L, 0) && can(R, new_k)) {
            // cerr << "dfs\n";
            dfs(L, 0, c);
            dfs(R, new_k, c);
            return;
        }
    }
}
void solve() {
    int n, k; cin >> n >> k;
    if (!can(n, k)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    dfs(n, k, 0);
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}