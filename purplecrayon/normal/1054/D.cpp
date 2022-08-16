#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto& c : a) cin >> c;
    map<int, int> cnt; cnt[0] = 1;
    ll ans = 0;
    int ps = 0;
    for (int c : a) {
        ps ^= c;
        int one = ps, two = (~ps) & ((1 << k) - 1);
        if (cnt[one] < cnt[two]) {
            ans += cnt[one]++;
        } else {
            ans += cnt[two]++;
        }
    }
    cout << (long long) n * (n + 1) / 2 - ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}