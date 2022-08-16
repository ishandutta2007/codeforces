#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e6+10, MOD = 1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin >> n >> m;
    set<ar<int, 2>> e;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        if (a > b) swap(a, b);
        e.insert({a, b});
    }

    int magic = max(200, MOD / n / 50);

    vector<int> p(n); std::iota(p.begin(), p.end(), 0);
    for (int rep = 0; rep < magic; rep++) {
        shuffle(p.begin(), p.end(), rng);
        bool bad = 0;
        for (int i = 0; i < m && !bad; i++) {
            int a = p[i], b = p[(i + 1) % n];
            if (a > b) swap(a, b);
            if (e.count({a, b})) bad = 1;
        }
        if (!bad) {
            for (int i = 0; i < m; i++) {
                int a = p[i], b = p[(i + 1) % n];
                cout << a+1 << ' ' << b+1 << '\n';
            }
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}