#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 9;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    auto b = a;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    range(i, n) a[i] = lower_bound(all(b), a[i]) - b.begin();
    set<int> low, high;
    vector<vector<int>> positions(n);
    range(i, n) {
        positions[a[i]].push_back(i);
        high.insert(i);
    }
    range(x, n) {
        for (auto &i: positions[x]) {
            high.erase(i);
        }
        if (positions[x].size() >= 3) {
            int L = n, R = n;
            if (!high.empty()) {
                L = *high.begin();
                R = *high.rbegin();
            }
            for (int j = 1; j + 1 < (int) positions[x].size(); ++j) {
                int i = positions[x][j];
                int l = L, r = R;
                if (l == n) {
                    l = r = i;
                } else {
                    l = min(l, i);
                    r = max(r, i);
                }
                auto it = low.lower_bound(l);
                auto it2 = low.lower_bound(r);
                if (it != it2) continue;
                if (positions[x][0] >= l) continue;
                if (positions[x].back() <= r) continue;
                cout << "YES\n";
                cout << l << " " << r - l + 1 << " " << n - r - 1 << "\n";
                return;
            }
        }
        for (auto &i: positions[x]) {
            low.insert(i);
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}