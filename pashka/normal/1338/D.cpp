#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<int> d;
vector<int> s1;
vector<int> s2;
int res = 0;

void dfs1(int x, int p) {
    s1[x] = d[x] - 2;
    s2[x] = 1;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            dfs1(y, x);
            s1[x] = max(s1[x], s2[y] + d[x] - 2);
            s2[x] = max(s2[x], s1[y] + 1);
        }
    }
//    cout << x << " " << s1[x] << " " << s2[x] << "\n";
    s2[x] = max(s1[x], s2[x]);
    res = max(res, s2[x]);
}

void dfs2(int x, int p, int ss1, int ss2) {
//    cout << x << " " << p << " " << ss1 << " " << ss2 << "\n";
    int s1mx1 = d[x] - 2;
    int s1mx1i = -1;
    int s1mx2 = -1;
    int s2mx1 = 1;
    int s2mx1i = -1;
    int s2mx2 = -1;
    if (p != -1) {
        s1mx1 = max(s1mx1, ss2 + d[x] - 2);
        s2mx1 = max(s2mx1, ss1 + 1);
        res = max(res, s1mx1);
        res = max(res, s2mx1);
    }
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            int s = s2[y] + d[x] - 2;
            if (s > s1mx1) {
                s1mx2 = s1mx1;
                s1mx1 = s;
                s1mx1i = y;
            } else if (s > s1mx2) {
                s1mx2 = s;
            }
            s = s1[y] + 1;
            if (s > s2mx1) {
                s2mx2 = s2mx1;
                s2mx1 = s;
                s2mx1i = y;
            } else if (s > s2mx2) {
                s2mx2 = s;
            }
        }
    }
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (y != p) {
            int s1mx = (y == s1mx1i ? s1mx2 : s1mx1);
            int s2mx = (y == s2mx1i ? s2mx2 : s2mx1);
            s2mx = max(s1mx, s2mx);
            dfs2(y, x, s1mx, s2mx);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    d.resize(n);
    s1.resize(n);
    s2.resize(n);
    for (int i = 0; i < n; i++) d[i] = g[i].size();
    dfs1(0, -1);
    dfs2(0, -1, 0, 0);
    cout << res << "\n";
    return 0;
}