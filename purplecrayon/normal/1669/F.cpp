#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    map<ll, int> mp;
    set<ll> one, two;
    vector<int> a(n); for (auto& x : a) cin >> x;
    ll sum = 0;
    ll pre = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        pre += a[i];
        mp[pre] += i + 1;
        one.insert(pre);
    }
    ll suf = 0;
    for (int i = n-1; i >= 0; i--) {
        suf += a[i];
        mp[suf] += n - i;
        two.insert(suf);
    }
    int ans = 0;
    for (auto& [k, v] : mp) {
        if (v <= n && one.count(k) && two.count(k)) {
            ans = max(ans, v);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}