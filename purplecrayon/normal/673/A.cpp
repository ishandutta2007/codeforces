#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    int p = 0;
    for (auto c : a) {
        if (c - p - 1 >= 15) {
            cout << min(90, p + 15) << '\n';
            return;
        }
        p = c;
    }
    cout << min(90, p + 15) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}