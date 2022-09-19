#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int n, m;
vector<int> p(m + 1);
vector<int> c(m + 1);

struct comp {
    vector<int> v0;
    vector<int> v1;
    int size() {
        return v0.size() + v1.size();
    }
    int min(bool last) {
        if (last) {
            if (c[m] == 0) return v1.size();
            else return v0.size();
        } else {
            return ::min(v1.size(), v0.size());
        }
    }
};
vector<comp> v(m + 1);

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> t(n);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int y; cin >> y;
            y--;
            t[y].push_back(i);
        }
    }

    v.resize(m + 1);
    p.resize(m + 1);
    c.resize(m + 1);
    for (int i = 0; i <= m; i++) {
        v[i].v0 = {i};
        p[i] = i;
        c[i] = 0;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].size() == 0) {
            cout << res << "\n";
            continue;
        }
        int x, y;
        if (t[i].size() == 2) {
            x = t[i][0];
            y = t[i][1];
        } else {
            x = t[i][0];
            y = m;
        }
        if (p[x] == p[y]) {
            cout << res << "\n";
            continue;
        }

        if (v[p[x]].size() > v[p[y]].size()) {
            swap(x, y);
        }

        res -= v[p[x]].min(p[x] == p[m]);
        res -= v[p[y]].min(p[y] == p[m]);

        int q = c[x] ^ c[y] ^ (s[i] - '0');
        if (q == 0) {
            for (int z : v[p[x]].v0) {
                c[z] = 1;
            }
            for (int z : v[p[x]].v1) {
                c[z] = 0;
            }
            swap(v[p[x]].v0, v[p[x]].v1);
        }
        int k = p[x];
        for (int z : v[k].v0) {
            v[p[y]].v0.push_back(z);
            p[z] = p[y];
        }
        for (int z : v[k].v1) {
            v[p[y]].v1.push_back(z);
            p[z] = p[y];
        }

        res += v[p[y]].min(p[y] == p[m]);
//        cout << "!! " << res << "\n";

        cout << res << "\n";
    }

    return 0;
}