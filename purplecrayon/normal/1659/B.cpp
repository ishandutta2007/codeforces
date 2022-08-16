#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (k % 2) for (auto& c : s) c ^= '0' ^ '1';

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && k) {
            k--;
            s[i] ^= '0' ^ '1';
            ans[i]++;
        }
    }

    ans[n-1] += k;

    if (k % 2) {
        s[n-1] ^= '0' ^ '1';
    }
    cout << s << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n'; 
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}