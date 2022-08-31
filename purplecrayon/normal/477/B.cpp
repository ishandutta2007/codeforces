#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;
const int M = 5e2+10;

void solve() {
    // you want 3 odd and 1 even per set
    // periodic mod 6?
    int n, k; cin >> n >> k;
    cout << k * (6 * (n - 1) + 5) << '\n';
    for (int i = 0; i < n; i++) {
        cout << k * (6 * i + 1) << ' ' << k * (6 * i + 3) << ' ' << k * (6 * i + 5) << ' ' << k * (6 * i + 4) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}