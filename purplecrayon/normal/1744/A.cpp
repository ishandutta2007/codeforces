#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<char> b(n); for (auto& x : b) cin >> x;
    map<int, char> mp;
    for (int i = 0; i < n; i++) mp[a[i]] = b[i];
    for (int i = 0; i < n; i++) if (mp[a[i]] != b[i]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}