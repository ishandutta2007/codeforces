#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> loc;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '0') {
            loc.push_back(i);
            b.push_back(a[i]);
        }
    }
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < sz(loc); i++) a[loc[i]] = b[i];
    for (auto c : a) cout << c << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}