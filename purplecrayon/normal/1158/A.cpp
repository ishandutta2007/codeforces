#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, m;
ll a[MAXN], b[MAXN];
map<ll, int> cnt;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a+n), sort(b, b+m);
    if (b[0] < a[n-1]) {
        cout << -1 << '\n';
        return;
    }
    if (b[0] == a[n-1]) {
        ll ans = (accumulate(a, a+n, 0ll)-a[n-1])*m + accumulate(b, b+m, 0ll);
        cout << ans << '\n';
        return;
    }
    ll ans = accumulate(a, a+n, 0ll)*m + accumulate(b, b+m, 0ll);
    ans -= a[n-1]*(m-1);
    ans -= a[n-2];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}