#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    range(i, n) cin >> p[i];
    range(i, n) p[i]--;
    vector<pair<int, int>> ans;
    vector<vector<int>> cycles;
    vector<bool> used(n);
    range(i, n) {
        if (used[i]) continue;
        cycles.emplace_back();
        while (!used[i]) {
            cycles.back().push_back(i);
            used[i] = true;
            i = p[i];
        }
        if (cycles.back().size() == 1) {
            cycles.pop_back();
        }
    }
    while (cycles.size() > 1) {
        auto v1 = cycles.back();
        cycles.pop_back();
        auto v2 = cycles.back();
        cycles.pop_back();
        ans.emplace_back(v1.front(), v2.front());
        swap(v1.front(), v2.front());
        for (int i = 1; i < v1.size(); ++i) {
            ans.emplace_back(v1[0], v1[i]);
        }
        for (int i = 1; i < v2.size(); ++i) {
            ans.emplace_back(v2[0], v2[i]);
        }
        ans.emplace_back(v1.front(), v2.front());
    }
    if (cycles.size() == 1) {
        auto v = cycles.back();
        int sz = v.size();
        if (sz == 2) {
            int y = 1;
            while (find(all(v), y) != v.end()) y++;
            ans.emplace_back(v[1], y);
            ans.emplace_back(v[0], y);
            ans.emplace_back(v[1], y);
        } else {
            ans.emplace_back(v[sz-1], v[sz-2]);
            ans.emplace_back(v[sz-3], v[sz-1]);
            range(i, sz - 2) {
                ans.emplace_back(v[i], v[sz-2]);
            }
            ans.emplace_back(v[sz-1], v[sz-2]);
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x + 1 << ' ' << y + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}