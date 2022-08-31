#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int x; cin >> x;
    int b = 0;
    while ((x >> b) & 1 ^ 1) b++;
    int y = 1 << b;
    while ((x & y) == 0 || (x ^ y) == 0) y++;
    cout << y << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}