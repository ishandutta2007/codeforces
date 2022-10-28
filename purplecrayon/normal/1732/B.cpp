#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = (s[0] - '0') - 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            ans++;
        }
    }
    cout << max(0, ans) << '\n';
    // it can change from 0's to 1's at most once
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}