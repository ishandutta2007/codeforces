#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int can = 0;
    for (int i = 0; i < n; i++) if (s[i] - 'a' > can) {
        if (s[i] - 'a' <= k) can = max(can, s[i] - 'a');
        else {
            k -= can;
            int X = s[i] - 'a', Y = s[i] - 'a' - k;
            for (int j = X; j > Y; j--) {
                for (auto& c : s) {
                    if (c - 'a' == j) c--;
                }
            }
            break;
        }
    }
    for (auto& c : s) {
        if (c - 'a' <= can) cout << 'a';
        else cout << c;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}