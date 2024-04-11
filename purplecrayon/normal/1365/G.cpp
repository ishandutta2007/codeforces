#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;

    int ptr = 0;
    vector<int> mask(n);

    const int M = 13;
    for (int i = 0; i < (1 << M) && ptr < n; i++) if (__builtin_popcount(i) == 5) {
        mask[ptr++] = i;
    }

    map<vector<int>, ll> memo;

    auto qry = [&](vector<int> v) {
        if (!sz(v)) return 0LL;
        if (memo.count(v)) return memo[v];

        cout << "? " << sz(v) << ' ';
        for (int x : v) cout << x+1 << ' ';
        cout << endl;
        ll x; cin >> x;
        return memo[v] = x;
    };

    vector<ll> ans(n);
    for (int i = 0; i < M; i++) {
        vector<int> one, two;
        for (int j = 0; j < n; j++) {
            if ((mask[j] >> i) & 1) one.push_back(j);
            else two.push_back(j);
        }
        ll x = qry(one);
        for (auto& j : two) ans[j] |= x;
    }
    cout << "! ";
    for (auto& x : ans) cout << x << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}