#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    ll sum = 0;
    for (int x : a) sum += x;
    if (sum != 0) {
        cout << "NO\n";
        return;
    }
    while (sz(a) && a.back() == 0) a.pop_back();
    if (!sz(a)) {
        cout << "YES\n";
        return;
    }
    ll ps = 0;
    for (int i = 0; i < sz(a)-1; i++) {
        ps += a[i];
        if (ps <= sum - ps) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}