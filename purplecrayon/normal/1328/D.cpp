#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (*std::min_element(a.begin(), a.end()) == *std::max_element(a.begin(), a.end())) {
        cout << 1 << '\n';
        while (n--) cout << 1 << ' ';
        cout << '\n';
        return;
    }
    if (n % 2 == 0) {
        cout << 2 << '\n';
        for (int i = 0; i < n; i++) cout << (i % 2) + 1 << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) if (a[i] == a[(i + 1)%n]) {
        cout << 2 << '\n';
        vector<int> ans(n);
        for (int d = 0; d < n; d++) {
            int c = d % 2 || d == 0;
            ans[(i + d) % n] = c + 1;
        }
        for (int x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    cout << 3 << '\n';
    cout << 3 << ' ';
    for (int i = 1; i < n; i++) {
        cout << (i % 2) + 1 << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}