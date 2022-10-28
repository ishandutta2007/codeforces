#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;

    vector<int> r(n, 1), l(n, 1);
    for (int i = 0; i < n; i++) {
        if (i && a[i-1] < a[i]) r[i] += r[i-1];
    }
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1 && a[i] < a[i+1]) l[i] += l[i+1];
    }

    int ans = *max_element(l.begin(), l.end());
    for (int i = 1; i < n-1; i++) {
        if (a[i-1] < a[i+1]) {
            ans = max(ans, r[i-1]+l[i+1]);
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