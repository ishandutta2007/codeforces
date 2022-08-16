#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    for (int i = n; i >= 1; i--) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i < n; i++) {
        cout << i << ' ' << n << ' ';
        for (int j = n-1; j >= 1; j--) if (j != i) cout << j << ' ';
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}