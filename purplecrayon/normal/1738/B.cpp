#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(k); for (auto& x : a) cin >> x;
    if (k == 1) {
        cout << "YES\n";
        return;
    }
    if (k == n) {
        a.insert(a.begin(), 0);
    }
    for (int i = 2; i < sz(a); i++) if (a[i] - a[i-1] < a[i-1] - a[i-2]) {
        cout << "NO\n";
        return;
    }
    if (k == n) {
        cout << "YES\n";
        return;
    }
    ll last = a[1] - a[0];
    if (last * (n - k + 1) < a[0]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}


// 101010101