#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    string s = "0110";
    string t = "1001";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i % 4 == 0 || i % 4 == 3 ? s : t)[j % 4] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}