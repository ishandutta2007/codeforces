#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int n;
vector<vector<int>> g;
vector<int> h;

vector<pair<long, int>> d1;
vector<vector<pair<long, int>>> ps;
vector<vector<pair<long, int>>> ss;

pair<long, int> sum(pair<long, int> &a, pair<long, int> &b) {
    return {a.first + b.first, max(a.second, b.second)};
}

pair<long, int> update(pair<long, int> &a, int hh) {
    auto res = a;
    if (res.second < hh) {
        res.first += hh - res.second;
        res.second = hh;
    }
    return res;
}

long res;

void dfs1(int x, int p) {
    vector<int> c;
    for (int y : g[x]) {
        if (y == p) continue;
        dfs1(y, x);
        c.push_back(y);
    }
    int k = c.size();
    ps[x].resize(k + 1);
    ss[x].resize(k + 1);
    for (int i = 0; i < k; i++) {
        ps[x][i + 1] = sum(ps[x][i], d1[c[i]]);
    }
    for (int i = k - 1; i >= 0; i--) {
        ss[x][i] = sum(ss[x][i + 1], d1[c[i]]);
    }
    d1[x] = ps[x][k];
    d1[x] = update(d1[x], h[x]);
}

void dfs2(int x, int p, pair<long, int> t) {
    vector<int> c;
    for (int y : g[x]) {
        if (y == p) continue;
        c.push_back(y);
    }
    int k = c.size();
    auto s = sum(t, d1[x]);
    if (c.size() == 0) {
        s = t;
    }
    s = update(s, h[x]);
//    cout << x << " " << s.first << " " << s.second << "\n";
    res = min(res, s.first + s.second);
    for (int i = 0; i < k; i++) {
        s = sum(ps[x][i], ss[x][i + 1]);
        s = sum(s, t);
        s = update(s, h[x]);
        dfs2(c[i], x, s);
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    h.resize(n);
    g.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d1.resize(n);
    ps.resize(n);
    ss.resize(n);
    dfs1(0, -1);
    res = d1[0].first + d1[0].second;

    int k = g[0].size();
    for (int i = 0; i < k; i++) {
        pair<long, int> s = sum(ps[0][i], ss[0][i + 1]);
        s = update(s, h[0]);
        dfs2(g[0][i], 0, s);
    }

    cout << res << "\n";

    return 0;
}