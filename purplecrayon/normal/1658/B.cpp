#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    if (n % 2 == 1) cout << 0 << '\n';
    else {
        n /= 2;
        int f = 1;
        for (int i = 1; i <= n; i++) f = ((long long) f * i) % MOD;
        cout << (long long) f * f % MOD << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}