#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int mx = -1, sm = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mx = max(mx, a), sm += a;
    }
    cout << max((2*sm+n)/n, mx) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}