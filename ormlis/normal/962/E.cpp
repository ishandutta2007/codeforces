#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

pair<ll, ll> get_ans(const vector<int> &b) {
    if (b.empty()) return {0, 0};
    ll cur = b.back() - b[0];
    ll mx = 0;
    for (int i = 1; i < b.size(); ++i) {
        mx = max(mx, (ll) b[i] - b[i - 1]);
    }
    return {cur, mx};
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r, b;
    r.emplace_back();
    b.emplace_back();
    int cg = 0;
    range(i, n) {
        int p;
        char c;
        cin >> p >> c;
        if (c == 'B') {
            b.back().push_back(p);
        }
        if (c == 'R') {
            r.back().push_back(p);
        }
        if (c == 'P') {
            cg++;
            r.back().push_back(p);
            r.push_back({p});
            b.back().push_back(p);
            b.push_back({p});
        }
    }
    ll ans = 0;
    for(int i = 0; i <= cg; ++i) {
        auto r1 = get_ans(r[i]);
        auto b1 = get_ans(b[i]);
        if (i == 0 || i == cg) ans += r1.first + b1.first;
        else ans += min(r1.first + b1.first, r1.first + b1.first - r1.second - b1.second + r[i].back() - r[i][0]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}