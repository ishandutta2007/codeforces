#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;
const ll INF = 1e18+10;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int cnt = 0;
    for (int x : a) if (x < 0) cnt++;
    for (int i = 0; i < n; i++) {
        if (i < cnt) a[i] = -abs(a[i]);
        else a[i] = abs(a[i]);
    }
    if (std::is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}