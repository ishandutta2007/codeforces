#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<string> a(n); for (auto& c : a) cin >> c;
    vector<ar<int, 5>> delta(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int x = 0;
            for (auto c : a[i]) {
                if (c-'a' == j) x++;
                else x--;
            }
            delta[i][j] = x;
        }
    }
    int ans = 0;
    for (int j = 0; j < 5; j++) {
        sort(delta.begin(), delta.end(), [&](auto u, auto v){ return u[j] > v[j]; });
        int cur = 0, x = 0;
        for (int i = 0; i < n; i++) {
            x += delta[i][j];
            if (x > 0) cur = i+1;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}