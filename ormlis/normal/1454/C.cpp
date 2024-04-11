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
    int n; cin >> n;
    vector<vector<int>> postions(n + 1);
    range(i, n) {
        int x; cin >> x;
        postions[x].push_back(i);
    }
    int ans = n;
    for(int i = 1; i <= n; ++i) {
        if (postions[i].empty()) continue;
        int p = -1;
        int res = 0;
        for(auto &x: postions[i]) {
            if (p + 1 != x) res++;
            p = x;
        }
        if (p != n - 1) res++;
        ans = min(ans, res);
    }
    cout << ans << "\n";
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