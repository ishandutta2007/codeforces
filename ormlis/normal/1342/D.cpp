#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2006;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> m(n);
    range(i, n) cin >> m[i];
    vector<int> c(k);
    range(i, k) cin >> c[i];
    vector<vector<int>> ans(1);
    set<pair<int, int>> lens = {{0, 0}};
    sort(rall(m));
    range(i, n) {
        int sz = m[i];
        int cnt = c[sz-1];
        if (lens.begin()->first >= cnt) {
            lens.insert({1, ans.size()});
            ans.push_back({sz});
        } else {
            auto p = *lens.begin();
            lens.erase(lens.begin());
            p.first += 1;
            ans[p.second].push_back(sz);
            lens.insert(p);
        }
    }
    cout << ans.size() << '\n';
    for(auto &x: ans) {
        cout << x.size() << ' ';
        for(auto &e: x) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}