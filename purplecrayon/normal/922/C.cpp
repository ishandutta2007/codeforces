#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    ll n, k; cin >> n >> k;
    if (k >= int(1e5)) {
        cout << "No\n";
        return;
    }
    set<ll> s;
    for (int i = 1; i <= k; i++) s.insert(n % i);
    if (sz(s) != k) cout << "No\n";
    else cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}