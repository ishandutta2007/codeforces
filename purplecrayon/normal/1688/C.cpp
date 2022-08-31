#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    ar<int, 26> cnt; cnt.fill(0);
    for (int rep = 0; rep < 2 * n + 1; rep++) {
        string s; cin >> s;
        for (auto c : s) cnt[c - 'a'] ^= 1;
    }
    for (int i = 0; i < 26; i++) if (cnt[i]) {
        cout << char(i + 'a') << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}