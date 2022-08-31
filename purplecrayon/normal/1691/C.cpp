#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int last = 0;
    for (int i = 0; i < sz(s); i++) if (s[i] == '1') last = i;
    if (n - last - 1 <= k) {
        for (int i = last; i < n-1; i++) {
            swap(s[i], s[i+1]);
        }
        k -= n - last - 1;
    }
    int first = 0;
    for (int i = 0; i < sz(s)-1; i++) if (s[i] == '1') {
        first = i;
        break;
    }
    if (first <= k) {
        for (int i = first; i > 0; i--) {
            swap(s[i], s[i-1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) if (s[i] == '1') ans += 10;
    for (int i = 1; i < n; i++) if (s[i] == '1') ans++; 
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}