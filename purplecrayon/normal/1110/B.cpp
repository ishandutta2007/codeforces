#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, m, k, a[MAXN], b[MAXN];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) b[i-1] = a[i]-a[i-1];
    }
    int gaps = n-k;
    sort(b, b+n-1);

    ll ans = k;
    for (int i = 0; i < gaps; i++) {
        ans += b[i];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}