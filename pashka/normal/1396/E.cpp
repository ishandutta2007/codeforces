#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int n, c;
vector<vector<int>> g;

int dfs(int x, int p) {
    bool ok = true;
    int s = 1;
    for (int y: g[x]) {
        if (y == p) continue;
        int ss = dfs(y, x);
        if (ss * 2 > n) ok = false;
        s += ss;
    }
    if (s * 2 < n) ok = false;
    if (ok) c = x;
    return s;
}

vector<long> d;

int dfs2(int x, int p) {
    int s = 1;
    for (int y: g[x]) {
        if (y == p) continue;
        int ss = dfs2(y, x);
        s += ss;
    }
    if (x != c) d[x] = s;
    return s;
}

vector<vector<int>> r;
vector<pair<int, int>> res;

void dfs3(int x, int p) {
    r[x].push_back(x);
    int s = 1;
    set<pair<int, int>> q;
    q.insert({-1, x});
    for (int y: g[x]) {
        if (y == p) continue;
        dfs3(y, x);
        q.insert({-r[y].size(), y});
        s += r[y].size();
    }
    while (s > d[x]) {
        s -= 2;
        auto p1 = *q.begin();
        q.erase(p1);
        auto p2 = *q.begin();
        q.erase(p2);
        assert(p1.first < 0 && p2.first < 0);
        p1.first++;
        p2.first++;
        q.insert(p1);
        q.insert(p2);
        int xx = r[p1.second].back();
        int yy = r[p2.second].back();
        res.push_back({xx, yy});
        r[p1.second].pop_back();
        r[p2.second].pop_back();
    }
    for (auto p : q) {
        int xx = p.second;
        if (xx != x) {
            if (r[xx].size() > r[x].size()) {
                r[x].swap(r[xx]);
            }
            for (int t : r[xx]) {
                r[x].push_back(t);
            }
        }
    }
    assert(r[x].size() == d[x]);
}

int main() {
    ios::sync_with_stdio(false);

    long k;
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    d.resize(n);
    dfs2(c, -1);
    long smax = 0;
    for (auto x : d) smax += x;
    long smin = 0;
    for (auto x : d) smin += x % 2;

    cerr << smin << " " << smax << "\n";
    if (k < smin || k > smax || k % 2 != smin % 2) {
        cout << "NO\n";
        return 0;
    }

    long l = 0;
    long r = n + 1;
    while (r > l + 1) {
        long m = (l + r) / 2;
        long s = 0;
        for (auto x : d) {
            if (x <= m) {
                s += x;
            } else {
                long y = (x - m + 1) / 2;
                s += x - 2 * y;
            }
        }
        if (s < k) l = m; else r = m;
    }
    for (auto &x : d) {
        if (x > r) {
            long y = (x - r + 1) / 2;
            x -= 2 * y;
        }
    }
    long s = 0;
    for (auto x : d) s += x;
    for (auto &x : d) {
        if (s > k && x == r) {
            x -= 2;
            s -= 2;
        }
    }
    assert(s == k);
//    for (auto x : d) cout << x << " ";
    ::r.resize(n);
    dfs3(c, -1);

    cout << "YES\n";
    for (auto e : res) {
        cout << e.first + 1  << " " << e.second + 1 << "\n";
    }

    return 0;
}