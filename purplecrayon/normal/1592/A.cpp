#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

void solve() {
    int n, h; cin >> n >> h;
    vector<int> a(n); for (auto& c : a) cin >> c;
    sort(a.rbegin(), a.rend());
    int x = a[0], y = a[1];

    int one = h/(x+y);
    int ans = 2*one;
    h -= one*(x+y);

    int me = x;
    while (h > 0) {
        h -= me;
        ans++;
        me ^= x ^ y;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}