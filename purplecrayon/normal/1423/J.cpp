#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

void solve() {
    ll m; cin >> m;
    ll a = m / 4 + 1; a %= MOD;
    ll b = m / 2 - m / 4 + 1; b %= MOD;
    cout << (a * b % MOD) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}