#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

ll req1(int i, int j, int k) {
    cout << 1 << " " << i << " " << j << " " << k << endl;
    ll res; cin >> res;
    return res;
}

int req2(int i, int j, int k) {
    cout << 2 << " " << i << " " << j << " " << k << endl;
    int res; cin >> res;
    return res;
}

vector<int> solve(vector<pair<ll, int>> &w, int start) {
    if (w.empty()) return {};
    sort(all(w));
    int k = w.back().second;
    w.pop_back();
    vector<int> left, right;
    range(i, (int)w.size()) {
        int z = req2(start, k, w[i].second);
        if (z == 1) left.emplace_back(w[i].second);
        else right.push_back(w[i].second);
    }
    left.push_back(k);
    reverse(all(right));
    for(auto &x: right) left.push_back(x);
    return left;
}

void solve() {
    int n; cin >> n;
    vector<pair<ll, int>> lower;
    vector<pair<ll, int>> upper;
    for(int i = 3; i <= n; ++i) {
        int z = req2(1, 2, i);
        ll s = req1(1, 2, i);
        if (z == 1) upper.emplace_back(s, i);
        else lower.emplace_back(s, i);
    }
    auto f = solve(upper, 1), e = solve(lower, 2);
    reverse(all(f));
    reverse(all(e));
    cout << "0 1 ";
    for(auto &x: e) cout << x << " ";
    cout << "2 ";
    for(auto &x: f) cout << x << " ";
}

int main() {
    /*
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    */
     int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}