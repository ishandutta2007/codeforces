#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18 + 100;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (k == 1) {
        if (a[0] == a[n-1]) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) if (a[i] != a[i-1]) cnt++;
    auto ceil_div = [&](int x, int y) {
        return (x + y - 1) / y;
    };
    cout << max(1, ceil_div(cnt, k - 1)) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}