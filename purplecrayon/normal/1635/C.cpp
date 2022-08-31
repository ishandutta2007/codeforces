#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (std::is_sorted(a.begin(), a.end())) {
        cout << 0 << '\n';
        return;
    }
    if (a[n-2] > a[n-1] || a[n-1] < 0) {
        cout << -1 << '\n';
        return;
    }
    cout << n-2 << '\n';
    for (int i = 0; i < n-2; i++) {
        cout << i+1 << ' ' << n-1 << ' ' << n << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}