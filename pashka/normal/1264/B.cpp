#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<int> p;

void dfs(int x) {
    while (g[x].size() > 0) {
        int y = g[x].back();
        g[x].pop_back();
        dfs(y);
    }
    p.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);

    int n = 4;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int x : a) m += x;
    for (int s = 0; s < n; s++) {
        for (int t = 0; t < n; t++) {
            g.clear();
            g.resize(n);
            vector<int> in = a;
            vector<int> out = a;
            in[s]--;
            out[t]--;
            bool ok = true;
            for (int i = 0; i < n - 1; i++) {
                if (in[i] < 0 || out[i] < 0) {
                    ok = false;
                    break;
                }
                for (int j = 0; j < in[i]; j++) {
                    g[i + 1].push_back(i);
                }
                for (int j = 0; j < out[i]; j++) {
                    g[i].push_back(i + 1);
                }
                in[i + 1] -= out[i];
                out[i + 1] -= in[i];
            }
            if (in[n - 1] != 0 || out[n - 1] != 0) {
                ok = false;
            }
            if (ok) {
                p.clear();
                dfs(s);
                if (p.size() != m) {
                    ok = false;
                }
                if (ok)
                for (int i = 0; i < m - 1; i++) {
                    if (abs(p[i] - p[i + 1]) != 1) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << "YES\n";
                for (int i : p) {
                    cout << i << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}