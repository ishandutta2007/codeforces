#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*239+v.second;
    }
};

struct test {
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        unordered_set<pair<int, int>, pair_hash> bad;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            bad.insert({x, y});
            bad.insert({y, x});
        }
        map<int, int> cnt;
        for (int i = 0; i < n; i++) cnt[a[i]]++;
        set<int> cc;
        for (auto p : cnt) {
            cc.insert(p.second);
        }
        vector<int> c;
        for (auto x: cc) c.push_back(x);
        int k = c.size();
        vector<vector<int>> g(k);
        for (auto p : cnt) {
            int i = lower_bound(c.begin(), c.end(), p.second) - c.begin();
            g[i].push_back(p.first);
        }
        long res = 0;
        for (auto p : cnt) {
            int x = p.first;
            int cx = p.second;
            bad.insert({x, x});
            for (int i = 0; i < k; i++) {
                for (int j = (int)g[i].size() - 1; j >= 0; j--) {
                    int y = g[i][j];
                    if (bad.find({x, y}) == bad.end()) {
                        res = max(res, (long)(x + y) * (c[i] + cx));
                        break;
                    }
                }
            }
        }
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}