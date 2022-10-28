#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int x = a - 1;
    int y = abs(c - b) + c - 1;
    if (x < y) cout << 1 << '\n';
    else if (x > y) cout << 2 << '\n';
    else cout << 3 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}