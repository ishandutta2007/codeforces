#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int x; cin >> x;
    // some number of 11's, and some number of 111's
    // less than 11 111's
    for (int a = 0; a <= 20; a++) {
        int y = x - a * 111;
        if (y >= 0 && y % 11 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}