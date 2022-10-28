#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& c : a) cin >> c;
    map<int, int> last;
    for (int i = 0; i < n; i++) last[a[i]] = i;

    int ans = 0;
    for (int i = 0; i < n; ) {
        int mx = last[a[i]];
        for (int j = i; j <= mx; j++) {
            mx = max(mx, last[a[j]]);
        }

        map<int, int> cur;
        for (int j = i; j <= mx; j++) cur[a[j]]++;
        int cnt = 0;
        for (auto& c : cur) cnt = max(cnt, c.second);
        ans += mx-i+1 - cnt;
        i = mx+1;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}