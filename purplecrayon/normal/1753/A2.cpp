#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    // [1, even number of 0's, -1]
    // just take individual segments
    // [1, odd number, -1]
    // just take the whole thing
    //
    // [1, even number of 0's, 1]
    // just take the whole thing
    //
    // [1, odd number of 0's, 1]
    // [1], [0...1]

    if (std::accumulate(a.begin(), a.end(), 0) % 2) {
        cout << -1 << '\n';
        return;
    }

    vector<pair<int, int>> ans;
    auto add_individual = [&](int L, int R) {
        for (int i = L; i <= R; i++) ans.emplace_back(i, i);
    };
    auto add_whole = [&](int L, int R) {
        ans.emplace_back(L, R);
    };

    int use = -1;
    for (int i = 0; i < n; i++) {
        if (use == -1) {
            if (a[i] == 0) {
                ans.emplace_back(i, i);
            } else {
                use = i;
            }
        } else {
            if (a[i] == 0) continue;
            // make segment
            if (a[i] == a[use]) {
                if ((i - use - 1) % 2 == 0) add_whole(use, i);
                else add_whole(use, use), add_whole(use + 1, i);
            } else {
                if ((i - use - 1) % 2 == 0) add_individual(use, i);
                else add_whole(use, i);
            }
            use = -1;
        }
    }

    cout << sz(ans) << '\n';
    for (auto [l, r] : ans) cout << l+1 << ' ' << r+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}