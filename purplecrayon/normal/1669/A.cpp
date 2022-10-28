#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    cout << "Division ";
    int x; cin >> x;
    if (1900 <= x) cout << 1 << '\n';
    else if (1600 <= x && x <= 1899) cout << 2 << '\n';
    else if (1400 <= x && x <= 1599) cout << 3 << '\n';
    else cout << 4 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}