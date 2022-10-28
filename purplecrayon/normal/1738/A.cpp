#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> b(n); for (auto& x : b) cin >> x;

    vector<int> one, two;
    for (int i = 0; i < n; i++) {
        if (a[i]) one.push_back(b[i]);
        else two.push_back(b[i]);
    }
    if (sz(one) == sz(two)) {
        ll ans = 0;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            ans += b[i];
            if (i) ans += b[i];
        }
        cout << ans << '\n';
        return;
    }
    sort(one.rbegin(), one.rend()), sort(two.rbegin(), two.rend());
    if (sz(one) < sz(two)) swap(one, two);
    ll ans = 0;
    for (int i = 0; i < sz(two); i++) {
        ans += 2LL * one[i] + 2LL * two[i];
    }
    for (int i = sz(two); i < sz(one); i++) ans += one[i];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}


// 101010101