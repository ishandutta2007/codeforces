#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    ll s, n, k; cin >> s >> n >> k;
    if (s == k) { cout << "YES\n"; return; }
    if (s < k) { cout << "NO\n"; return; }
    if (s - n < (n / k) * k) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}