#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
        int x; cin >> x;
        mp[x]++;
    }
    for (auto& [k, v] : mp) {
        if (v >= 3) {
            cout << k << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}