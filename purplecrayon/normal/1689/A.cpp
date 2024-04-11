#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s, t; cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int p1 = 0, p2 = 0;
    bool last = 0; int cnt = 0;

    string ans;
    auto zero = [&]() {
        ans += s[p1++];
        if (last == 0) cnt++;
        else last = 0, cnt = 1;
    };
    auto one = [&]() {
        ans += t[p2++];
        if (last == 1) cnt++;
        else last = 1, cnt = 1;
    };

    while (p1 < sz(s) && p2 < sz(t)) {
        bool can0 = last != 0 || cnt < k;
        bool can1 = last != 1 || cnt < k;
        if (!can0) one();
        else if (!can1) zero();
        else if (s[p1] < t[p2]) zero();
        else one();
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}