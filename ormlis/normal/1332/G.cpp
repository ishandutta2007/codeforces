#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<pair<int, vector<int>>> check(vector<int> &a, vector<pair<int, int>> &req) {
    int n = a.size();
    vector<pair<int, vector<int>>> res(req.size(), {0, {}});

    vector<int> ml(n, -1), bl(n, -1), mp(n, n), bp(n, n);
    vector<int> stk;

    range(i, n) {
        while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
        if (!stk.empty()) ml[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    range(i, n) {
        while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
        if (!stk.empty()) bl[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
        if (!stk.empty()) mp[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
        if (!stk.empty()) bp[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();


    vector<vector<int>> dp(n, {-1, -1, -1});
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (bl[i] != -1) {
            int left = ml[bl[i]];
            dp[i] = max(dp[i], {left, bl[i], i});
        }
        if (ml[i] != -1) {
            int left = bl[ml[i]];
            dp[i] = max(dp[i], {left, ml[i], i});
        }
    }

    range(i, res.size()) {
        if (dp[req[i].second - 1][0] >= req[i].first - 1) {
            res[i] = {3, dp[req[i].second - 1]};
        }
    }

    vector<vector<int>> need_to_add(n);

    range(i, n) {
        int right = max(bp[i], mp[i]);
        if (right != n) need_to_add[right].push_back(i);
    }

    set<int> current;
    vector<vector<int>> dp2(n, {-1, -1, -1, -1});
    range(i, n) {
        int left = min(bl[i], ml[i]) - 1;
        auto j = current.upper_bound(left);
        if (!current.empty() && j != current.begin()) {
            j--;
            int x = *j;
            int i2, i3;
            if (a[x] < a[i]) {
                i2 = mp[x];
                i3 = bl[i];
            } else {
                i2 = ml[i];
                i3 = bp[x];
            }
            if (i2 > i3) swap(i2, i3);
            dp2[i] = {x, i2, i3, i};
        }
        if (i) dp2[i] = max(dp2[i-1], dp2[i]);
        for(auto &x: need_to_add[i]) {
            current.insert(x);
        }
    }
    range(i, req.size()) {
        if (req[i].first-1 <= dp2[req[i].second-1][0]) {
            res[i] = {4, dp2[req[i].second-1]};
        }
    }
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<pair<int, int>> req(q);
    range(i, q) {
        int l, r; cin >> l >> r;
        req[i] = {l, r};
    }
    auto ans = check(a, req);
    range(i, q) {
        cout << ans[i].first << "\n";
        range(j, ans[i].first) cout << ans[i].second[j]  + 1<< " ";
        cout << "\n";
    }
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