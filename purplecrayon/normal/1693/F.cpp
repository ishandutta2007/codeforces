#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int cnt[2] = {};
    for (char c : s) cnt[c - '0']++;
    if (cnt[1] > cnt[0]) {
        for (auto& c : s) c ^= '0' ^ '1';
        reverse(s.begin(), s.end());
        swap(cnt[0], cnt[1]);
    }
    if (is_sorted(s.begin(), s.end())) {
        cout << 0 << '\n';
        return;
    }

    vector<int> ps(n);
    for (int i = 0; i < n; i++) ps[i] = (i ? ps[i-1] : 0) + (s[i] == '1' ? +1 : -1);
    auto suf = ps;
    for (int i = n-2; i >= 0; i--) suf[i] = max(suf[i], suf[i+1]);

    int ans = 0;
    int c = -1;
    for (int i = 0; i < n; i++) if (s[i] == '1') {
        c = i;
        break;
    }

    int ones = 0;
    while (c < n) {
        ans++;

        int r = -1;
        int bound = (c ? ps[c-1] : 0) - ones;
        for (int i = c; i < n; i++) {
            if (suf[i] < bound) break;
            r = i;
        } 

        for (int i = c; i <= r; i++) ones += s[i] == '1';
        c = r + 1;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}