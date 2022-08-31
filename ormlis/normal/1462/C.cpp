#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int x; cin >> x;
    if (x > 45) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for(int i = 9; i >= 1; --i) {
        if (x <= i) break;
        ans.push_back(i);
        x -= i;
    }
    ans.push_back(x);
    reverse(all(ans));
    for(auto &w : ans) cout << w;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}