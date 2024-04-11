#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int a, b; cin >> a >> b;
    char c = '0';
    if (a < b) swap(a, b), c ^= '0' ^ '1';
    for (int r = 0; a || b; r ^= 1) {
        if ((a && r == 0) || !b) cout << c, a--;
        else cout << char(c ^ '0' ^ '1'), b--;
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}