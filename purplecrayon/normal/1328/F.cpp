#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, k, a[MAXN];
ll ps[MAXN];

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        ps[i] = a[i];
        if (i) ps[i] += ps[i-1];
    }

    ll ans = INF;
    int ptr = 0;

    auto get = [&](int i) -> ll { return i < 0 ? 0 : ps[i]; };

    for (int i = 0; i < n; i = ptr) {
        while (ptr < n && a[i] == a[ptr]) ptr++;

        int cnt_eq = ptr-i, merge = k-cnt_eq;
        if (merge <= 0) {
            cout << 0 << '\n';
            return;
        }

        ll x = a[i];
        ll dist_left = (x-1)*i-get(i-1), dist_right = (get(n-1)-get(ptr-1))-(x+1)*(n-ptr);
        if (cnt_eq + i >= k) ans = min(ans, dist_left+merge);
        if (cnt_eq + n-ptr >= k) ans = min(dist_right+merge, ans);
        ans = min(ans, dist_left+dist_right+merge);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}