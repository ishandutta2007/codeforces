#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> loc(2*n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a, --a;
        loc[a] = i;
    }
    for (int i = 0; i < n; i++) {
        int b; cin >> b, --b;
        loc[b] = i;
    }
    int mn = n;
    int ans = 2*n;
    for (int i = 2*n-1; i >= 0; i--) {
        if (i&1) mn = min(mn, loc[i]);
        else ans = min(ans, loc[i]+mn);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}