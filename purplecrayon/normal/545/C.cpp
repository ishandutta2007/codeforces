#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int l = -MOD, r = -MOD;
    int ans = 0;

    auto bad = [&](int a, int b) {
        return !(b < l || a > r);
    };

    vector<ar<int, 2>> a(n); for (auto& it : a) cin >> it[0] >> it[1];

    for (int i = 0; i < n; i++) {
        int x = a[i][0], h = a[i][1];
        if (!bad(x-h, x)) ans++, l = x-h, r = x;
        else if (!bad(x, x+h) && (i == n-1 || a[i+1][0] < x || a[i+1][0] > x+h)) ans++, l = x, r = x+h;
        else l = x, r = x;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}