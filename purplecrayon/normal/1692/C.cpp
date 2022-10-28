#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n = 8;
    vector<string> v(n);
    for (auto& s : v) cin >> s;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            int cnt = 0;
            for (int a : {i-1, i+1}) {
                for (int b : {j-1, j+1}) {
                    if (v[a][b] == '#') cnt++;
                }
            }
            if (cnt == 4) {
                cout << i+1 << ' ' << j+1 << '\n';
                return;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}