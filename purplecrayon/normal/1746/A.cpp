#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 20, MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    while (n--) {
        int x; cin >> x;
        ans |= x;
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}