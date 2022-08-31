#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    ll w = 0;
    for (auto& x : a) w += x;
    if (w == 1) {
        cout << "YES\n";
        return;
    }

    map<int, int> cnt;
    for (auto x : a) cnt[x]++;

    vector<ll> can; can.push_back(w);
    while (sz(can)) {
        vector<ll> new_can;
        for (auto x : can) {
            if (cnt[x]) {
                cnt[x]--;
            } else if (x > 1) {
                new_can.push_back(x / 2);
                new_can.push_back((x + 1) / 2);
            }
        }
        can = new_can;
        if (sz(can) > n) {
            cout << "NO\n";
            return;
        }
    }
    for (auto& [_, k] : cnt) {
        if (k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}