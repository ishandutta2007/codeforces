#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    int x = n * m % 3;
    if (x == 0) {
        cout << n * m / 3 << '\n';
    } else if (x == 1) {
        cout << (n * m - 4) / 3 + 2 << '\n';
    } else if (x == 2) {
        cout << n * m / 3 + 1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}