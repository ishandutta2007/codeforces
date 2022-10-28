#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;

    const int M = 'k' - 'a' + 1;
    ll ans = 0;
    while (n--) {
        string s; cin >> s;
        for (int one = 0; one < M; one++) if (one != s[0] - 'a') {
            int cur = one * M + (s[1] - 'a');
            ans += mp[cur];
        }
        for (int two = 0; two < M; two++) if (two != s[1] - 'a') {
            int cur = (s[0] - 'a') * M + two;
            ans += mp[cur];
        }
        mp[(s[0] - 'a') * M + (s[1] - 'a')]++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}