#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    vector<vector<int>> g1, g2;
    vector<int> in, out;
    int t = 0;

    void dfs2(int x) {
        in[x] = t++;
        for (int y : g2[x]) dfs2(y);
        out[x] = t++;
    }

    set<pair<int, int>> s;
    int res = 0;

    void dfs1(int x) {
        pair<int, int> removed = {0, 0};
        auto p = s.lower_bound({in[x], 0});
        if (p != s.begin()) {
            --p;
            assert(in[x] > p->first);
            if (out[x] < p->second) {
                removed = *p;
                s.erase(p);
            }
        }
        s.insert({in[x], out[x]});
        res = max(res, (int)s.size());
        for (int y: g1[x]) dfs1(y);
        s.erase({in[x], out[x]});
        if (removed.first) {
            s.insert(removed);
        }
    }

    void solve_test() {
        int n;
        cin >> n;
        g1.resize(n);
        g2.resize(n);
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            g1[x - 1].push_back(i);
        }
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            g2[x - 1].push_back(i);
        }
        in.resize(n);
        out.resize(n);
        dfs2(0);
        dfs1(0);
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}