#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n); for (auto& c : p) cin >> c;
    reverse(p.begin(), p.end());
    for (auto c : p) cout << c << ' ';
    cout << '\n';
}
int main() {
    int T; cin >> T;
    while (T--) solve();
}