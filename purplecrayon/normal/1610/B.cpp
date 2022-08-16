#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

bool can(vector<int> a, int x) {
    vector<int> b;
    for (int v : a) if (v != x) b.push_back(v);
    for (int l = 0, r = sz(b)-1; l < r; l++, r--) if (b[l] != b[r]) return 0;
    return 1;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    for (int l = 0, r = n-1; l < r; l++, r--) {
        if (a[l] != a[r]) {
            if (can(a, a[l]) || can(a, a[r])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}