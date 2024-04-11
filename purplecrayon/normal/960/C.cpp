#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    int x, d; cin >> x >> d;
    ll use = 1;
    vector<ll> ans;
    while (x) {
        int m = 1;
        while ((1 << m) - 1 <= x) {
            m++;
        }
        m--;

        for (int i = 0; i < m; i++) ans.push_back(use);
        use += d + 1;

        x -= (1 << m) - 1;
    }
    cout << sz(ans) << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}