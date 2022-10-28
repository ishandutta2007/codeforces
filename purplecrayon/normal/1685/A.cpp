#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    if (n % 2) {
        cout << "NO\n";
        return;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) b[i] = a[i / 2];
        else b[i] = a[i / 2 + n / 2];
    }
    for (int i = 0; i < n; i++) {
        int prv = b[(i - 1 + n) % n];
        int nxt = b[(i + 1) % n];
        if ((prv < b[i] && b[i] > nxt) || (prv > b[i] && b[i] < nxt));
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int x : b) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}