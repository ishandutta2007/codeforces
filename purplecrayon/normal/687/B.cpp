#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

int n, k;
int a[MAXN];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    // lcm(a) % k != 0
    ll l = 1;
    for (int i = 0; i < n; i++) {
        l = lcm(l, a[i]);
        l = gcd(l, k);
    }
    if (l%k == 0) cout << "Yes\n";
    else cout << "No\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}