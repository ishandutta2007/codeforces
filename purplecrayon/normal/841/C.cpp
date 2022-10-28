#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e4+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<int> b(n); for (auto& x : b) cin >> x;

    vector<int> pa(n); iota(pa.begin(), pa.end(), 0);
    sort(pa.begin(), pa.end(), [&](int x, int y) { return a[x] < a[y]; });

    vector<int> pb(n); iota(pb.begin(), pb.end(), 0);
    sort(pb.begin(), pb.end(), [&](int x, int y) { return b[x] < b[y]; });

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[pb[i]] = a[pa[n-1-i]];
    }
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}