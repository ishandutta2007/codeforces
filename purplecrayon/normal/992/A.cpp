#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    set<int> s;
    while (n--) {
        int x; cin >> x;
        if (x) s.insert(x);
    }
    cout << sz(s) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}