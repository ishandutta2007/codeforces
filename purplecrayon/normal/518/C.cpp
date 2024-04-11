#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, m, k;
int a[MAXN], loc[MAXN];

void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i], loc[a[i]] = i;

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        int c; cin >> c, --c;
        ans += loc[c]/k+1;
        if (loc[c]) {
            loc[c]--;
            swap(a[loc[c]+1], a[loc[c]]), loc[a[loc[c]+1]]++;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}