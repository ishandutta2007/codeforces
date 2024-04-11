#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

// every time I sqrt it, it must be a perfect square that's a multiple of (k+1)^2
// k*(k+2) -> 1 less than (k+1)^2
// add k+2 times to subtract one from the count

ll sq(ll x) { return x*x; }
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << (long long) i * sq(i + 1) - i + 1 << '\n';
        else 
            cout << 2 << '\n';
            
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}