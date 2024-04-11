#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

int cnt[N];

void solve() {
    int x; cin >> x;
    string s; cin >> s;

    for (int l = 0; l < sz(s); l++) {
        int sum = 0;
        for (int r = l; r < sz(s); r++) {
            sum += s[r] - '0';
            cnt[sum]++;
        }
    }
    if (x == 0) {
        ll z = cnt[0];
        ll n = sz(s);
        cout << z * n * (n + 1) - z * z << '\n';
        return;
    }

    ll ans = 0;
    for (int l = 0; l < sz(s); l++) {
        int sum = 0;
        for (int r = l; r < sz(s); r++) {
            sum += s[r] - '0';
            if (sum > 0 && x % sum == 0 && x / sum < N)
                ans += cnt[x / sum];
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}