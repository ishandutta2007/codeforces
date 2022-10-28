#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 1e9+7;

void solve() {
    int r, c; cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << '\n';
        return;
    }
    if (c == 1) {
        for (int i = 1; i <= r; i++) cout << i+1 << '\n';
        return;
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << i * (r + j) << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}