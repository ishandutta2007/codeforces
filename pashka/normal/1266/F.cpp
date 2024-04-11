#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<int> d;
vector<int> d2;
vector<vector<int>> dd;

void dfs(int xx) {
    vector<pair<int, int>> st;
    st.push_back({xx, -1});
    for (int i = 0; i < st.size(); i++) {
        int x = st[i].first;
        int p = st[i].second;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (y != p) {
                st.push_back({y, x});
            }
        }
    }
    for (int i = st.size() - 1; i >= 0; i--) {
        int x = st[i].first;
        int p = st[i].second;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (y != p) {
                d[x] = max(d[x], d[y] + 1);
                dd[x].push_back(d[y] + 1);
            }
        }
    }
}

void dfs2(int xx) {
    vector<pair<int, int>> st;
    st.push_back({xx, -1});
    while (!st.empty()) {
        int x = st.back().first;
        int p = st.back().second;
        st.pop_back();
        int mx1 = -1;
        int mx2 = -1;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (y == p) continue;
            if (mx1 == -1 || d[y] > d[mx1]) {
                mx2 = mx1;
                mx1 = y;
            } else if (mx2 == -1 || d[y] > d[mx2]) {
                mx2 = y;
            }
        }
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (y != p) {
                int s = -1;
                if (mx2 != -1 && mx2 != y) {
                    s = d[mx2];
                }
                if (mx1 != -1 && mx1 != y) {
                    s = d[mx1];
                }
                d2[y] = max(d2[x] + 1, s + 2);
                dd[y].push_back(d2[y]);
                st.push_back({y, x});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

//    freopen("input", "r", stdin);

    int n;
    cin >> n;
    g.resize(n);

    vector<int> xx(n - 1);
    vector<int> yy(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        xx[i] = x;
        yy[i] = y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    d.resize(n);
    d2.resize(n);
    dd.resize(n);
    dfs(0);
    dfs2(0);
//    for (int i = 0; i < n; i++) {
//        cout << i + 1 << " " << d[i] << " " << d2[i] << ": ";
//        for (int x : dd[i]) {
//            cout << x << " ";
//        }
//        cout << "\n";
//    }

    vector<int> res(2 * n + 1, 1);
    for (int i = 0; i < n; i++) {
        res[1] = max(res[1], (int) g[i].size() + 1);
    }

    for (int i = 0; i < n; i++) {
        vector<int> &v = dd[i];
        sort(v.begin(), v.end());
        for (int l = 0; l < v.size(); l++) {
            if (l > 0 && v[l - 1] == v[l]) continue;

            int c = v[l];
            int s = v.size() - l;
            res[2 * c] = max(res[2 * c], s);

            res[2 * c - 1] = max(res[2 * c - 1], s);

            if (l > 0) {
                c = v[l - 1] + 1;
                s++;
            }
            res[2 * c - 1] = max(res[2 * c - 1], s);
        }
    }
    vector<vector<pair<int, int>>> dd2(n);
    for (int i = 0; i < n; i++) {
        for (int x : dd[i]) {
            if (dd2[i].size() > 0 && dd2[i].back().first == x) {
                dd2[i].back().second++;
            } else {
                dd2[i].push_back({x, 1});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int x = xx[i];
        int y = yy[i];

        auto &v = dd2[x];
        auto &u = dd2[y];
        int s1 = dd[x].size();
        int s2 = dd[y].size();

        int ii = 0;
        int jj = 0;
        while (ii < v.size() && jj < u.size()) {
            int s = s1 + s2 - 2;
            int c = min(v[ii].first, u[jj].first);
            res[2 * c] = max(res[2 * c], s);
            if (v[ii] < u[jj]) {
                s1 -= v[ii].second;
                ii++;
            } else {
                s2 -= u[jj].second;
                jj++;
            }
        }
    }


    for (int i = n - 2; i >= 1; i--) {
        res[i] = max(res[i], res[i + 2]);
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}