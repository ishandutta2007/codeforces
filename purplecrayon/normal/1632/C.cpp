#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int a, b; cin >> a >> b;
    int ans = b - a;
    for (int A = a; A <= b; A++) {
        ans = min(ans, A - a + 1 + (A | b) - b);
    }
    for (int B = b; B <= 2 * b; B++) {
        ans = min(ans, B - b + 1 + (a | B) - B);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}