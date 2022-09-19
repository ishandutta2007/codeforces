#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<pair<int, long>> d1;
vector<pair<int, long>> d2;
vector<long> t;
vector<int> h;

pair<int, long> add(pair<int, long> a, pair<int, long> b) {
    return {a.first + b.first, a.second + b.second};
}
pair<int, long> sub(pair<int, long> a, pair<int, long> b) {
    return {a.first - b.first, a.second - b.second};
}

void dfs(int x, int p) {
    vector<pair<int, long>> a;
    pair<int, long> s;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            dfs(y, x);
            s = add(s, d1[y]);
            a.push_back(sub(d2[y], d1[y]));
        }
    }
    sort(a.begin(), a.end());
    d1[x] = {1, 0};
    d2[x] = {1, 0};
    for (int q = 0; q <= a.size(); q++) {
        int w = a.size() - q;
        if (s.first == 0) {
            if (p == -1) {
                long z = max(q, w) * t[x] + s.second;
                if (d1[x].first || z < d1[x].second) {
                    d1[x] = {0, z};
                }
            } else {
                if (h[p] >= h[x]) {
                    long z = max(q + 1, w) * t[x] + s.second;
                    if (d1[x].first || z < d1[x].second) {
                        d1[x] = {0, z};
                    }
                }
                if (h[p] <= h[x]) {
                    long z = max(q, w + 1) * t[x] + s.second;
                    if (d2[x].first || z < d2[x].second) {
                        d2[x] = {0, z};
                    }
                }
            }
        }
        if (q < a.size()) {
            s = add(s, a[q]);
        }
    }
//    cout << p << "->" << x << "\n";
//    cout << d1[x].first << " " << d1[x].second << "\n";
//    cout << d2[x].first << " " << d2[x].second << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    t.resize(n);
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d1.resize(n);
    d2.resize(n);
    dfs(0, -1);
    cout << d1[0].second << "\n";

    return 0;
}