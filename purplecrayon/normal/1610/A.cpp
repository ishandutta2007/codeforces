#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    if (n == 1 && m == 1) cout << 0 << '\n';
    else if (min(n, m) == 1) cout << 1 << '\n';
    else cout << 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}