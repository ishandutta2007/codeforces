#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (auto& c : a) cin >> c;
    if (k >= 4) k = 4 + k%2;
    while (k--) {
        ll d = *max_element(a.begin(), a.end());
        for (auto& c : a) c = d-c;
    }
    for (auto c : a) cout << c << ' '; cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}