#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    // 1, 2, 3, ..., k - (n - k + 1)
    // 1, 2, 3, ..., 2 * k - n - 1
    //
    // k, k - 1, ..., k - (n - k)
    // k, k - 1, ..., 2 * k - n

    int n, k; cin >> n >> k;
    for (int i = 1; i <= 2 * k - n - 1; i++) {
        cout << i << ' ';
    }
    for (int i = k; i >= 2 * k - n; i--) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}