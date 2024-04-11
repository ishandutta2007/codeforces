#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g, gr;
vector<bool> z;
vector<int> p;

void dfs1(int x) {
    if (z[x]) return;
    z[x] = true;
    for (int y : g[x]) dfs1(y);
    p.push_back(x);
}

vector<int> c;
int cc;
void dfs2(int x) {
    if (z[x]) return;
    z[x] = true;
    c[x] = cc;
    for (int y : gr[x]) dfs2(y);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    g.resize(n * m);
    gr.resize(n * m);
    vector<bool> alive(n * m);
    z.resize(n * m);
    for (int j = 0; j < m; j++) {
        int ii = -1;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '#') {
                alive[i * m + j] = true;
                if (ii != -1) {
                    g[ii * m + j].push_back(i * m + j);
                    gr[i * m + j].push_back(ii * m + j);
                    if (i == ii + 1) {
                        g[i * m + j].push_back(ii * m + j);
                        gr[ii * m + j].push_back(i * m + j);
                    }
                }
                ii = i;
            }
        }
    }
    for (int j = 0; j < m - 1; j++) {
        int ii = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j + 1] == '#') {
                while (ii < n && (ii < i || s[ii][j] == '.'))
                    ii++;
                if (ii < n) {
                    g[i * m + j + 1].push_back(ii * m + j);
                    gr[ii * m + j].push_back(i * m + j + 1);
                }
            }
        }
    }
    for (int j = 0; j < m - 1; j++) {
        int ii = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '#') {
                while (ii < n && (ii < i || s[ii][j + 1] == '.'))
                    ii++;
                if (ii < n) {
                    g[i * m + j].push_back(ii * m + j + 1);
                    gr[ii * m + j + 1].push_back(i * m + j);
                }
            }
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (alive[i]) dfs1(i);
    }
    z.assign(n * m, false);
    c.resize(n * m);
    reverse(p.begin(), p.end());
    for (int i : p) {
        if (alive[i] && !z[i]) {
            dfs2(i);
            cc++;
        }
    }
    vector<bool> bd(cc);
    for (int x = 0; x < n * m; x++) {
        for (int y : g[x]) {
            if (c[x] != c[y])
                bd[c[y]] = true;
        }
    }
    int res = 0;
    for (int x = 0; x < cc; x++) if (!bd[x]) res++;
    cout << res << "\n";

    return 0;
}