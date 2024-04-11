#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 6e3 + 5;

int dp[N][N];
set<int> v[N];

int recurse(int l, int r) {
//    cout << l << " " << r << "\n";
    if (dp[l][r] != -1)
        return dp[l][r];

    if (l > r)
        return 0;

    int ans = 0;

    for (int i : v[r]) {
        if (i <= l) continue;
        ans = max(ans, recurse(i, r) + recurse(l, i - 1)); //0 4, 1 3, 1 2, 2 3
    }

    ans = max(ans, recurse(l, r - 1));
    return dp[l][r] = ans + (v[r].find(l) != v[r].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);

        vector<int> points;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            points.push_back(a[i].first);
            points.push_back(a[i].second);
        }

        sort(all(points));
        points.resize(unique(all(points)) - points.begin());

        for (auto &[l, r] : a) {
            l = lower_bound(all(points), l) - points.begin();
            r = lower_bound(all(points), r) - points.begin();
        }

        for (int i = 0; i < points.size(); i++) for (int j = 0; j < points.size(); j++) dp[i][j] = -1;

        for (auto &[l, r] : a) v[r].insert(l);
        cout << recurse(0, points.size() - 1) << "\n";
        for (auto &[l, r] : a) v[r].clear();
    }
    return 0;
}