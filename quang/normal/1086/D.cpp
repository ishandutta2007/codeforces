#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, q;
map<char, int> M;

struct IT {
    int t[N << 2];

    void init(int node, int l, int r) {
        t[node] = 0;
        if (l == r) return;
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
    }

    void update(int node, int l, int r, int id, int val) {
        if (id < l || id > r) return;
        if (l == r) {
            t[node] = val;
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, id, val);
        update(node << 1 | 1, m + 1, r, id, val);
        t[node] = t[node << 1] + t[node << 1 | 1];
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return 0;
        if (x <= l && r <= y) {
            return t[node];
        }
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return p1 + p2;
    }
} t[3];

set<int> s[3];
string a;

int getRes() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (s[(i + 1) % 3].empty()) {
            res += t[i].get(1, 1, n, 1, n);  
            continue;
        }
        if (s[(i + 2) % 3].empty()) {
            continue;
        }
        vector<pair<int, int> > foo, bar;
        int a = *s[(i + 1) % 3].rbegin();   
        int b = *s[(i + 2) % 3].rbegin();   
        if (a < b) {
            foo.push_back({1, n});
        } else {
            foo.push_back({1, b - 1});
            foo.push_back({a + 1, n});
        }
        a = *s[(i + 1) % 3].begin();   
        b = *s[(i + 2) % 3].begin();   
        if (a < b) {
            bar.push_back({1, a - 1});
            bar.push_back({b + 1, n});
        } else {
            bar.push_back({1, n});
        }

        for (auto u : foo) {
            for (auto v : bar) {
                int mn = max(u.first, v.first);
                int mx = min(u.second, v.second);
                if (mn <= mx) {
                    res += t[i].get(1, 1, n, mn, mx);
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    M['R'] = 0;
    M['P'] = 1;
    M['S'] = 2;
    cin >> n >> q;
    for (int i = 0; i < 3; i++) t[i].init(1, 1, n);
    cin >> a;
    a = "Q" + a;
    for (int i = 1; i <= n; i++) {
        int id = M[a[i]];
        s[id].insert(i);
        t[id].update(1, 1, n, i, 1);
    }
    cout << getRes() << '\n';
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        int id = M[a[p]];
        s[id].erase(p);
        t[id].update(1, 1, n, p, 0);
        id = M[c];
        a[p] = c;
        s[id].insert(p);
        t[id].update(1, 1, n, p, 1);
        cout << getRes() << '\n';
    }
    return 0;
}