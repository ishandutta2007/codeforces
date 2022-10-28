#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    int x = 0;
    for (auto c : a) x ^= c;

    vector<int> ops;
    auto solve = [&](int l, int r) {
        for (int i = l; i < r; i += 2) ops.push_back(i);
        for (int i = r-4; i >= l; i -= 2) ops.push_back(i);
    };
    auto print = [&]() {
        cout << "YES\n";
        cout << sz(ops) << '\n';
        for (auto c : ops) cout << c+1 << ' ';
        cout << '\n';
    };

    if (x) {
        cout << "NO\n";
        return;
    }
    if (n%2) {
        solve(0, n-1);
        print();
        return;
    }
    int y = 0;
    for (int i = 0; i < n; i++) {
        y ^= a[i];
        if (i%2 == 0 && y == 0) {
            solve(0, i);
            solve(i+1, n-1);
            print();
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}