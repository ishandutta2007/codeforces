#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> cnt(n + 1);
    for (auto& x : a) cnt[x]++;

    ll ans = 0;
    vector<int> s;
    for (int i = 0; i <= n; i++) {
        if (i) {
            while (cnt[i-1]--) {
                s.push_back(i-1);
            }
            if (!sz(s)) {
                for (int j = i; j <= n; j++) cout << -1 << ' ';
                cout << '\n';
                return;
            }
            ans += i-1 - s.back();
            s.pop_back();
        }
        cout << ans + cnt[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}