#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka


int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back({y, i + 1});
        g[y].push_back({x, i + 1});
    }

    vector<int> d(n, -1);
    vector<bool> z(n);

    vector<vector<int>> go(1, vector<int>(10, -1));
    vector<vector<int>> vv(1, vector<int>(1, 0));
    vector<int> h(1);

    vector<int> cur(1);

    while (cur.size() > 0) {
        vector<int> cur2;
        for (int v : cur) {
            for (int x : vv[v]) {

//                cout << h[v] << " " << x << "\n";

                if (z[x]) continue;
                z[x] = true;
                d[x] = h[v];
                for (auto e : g[x]) {
                    vector<int> dd;
                    int k = e.second;
                    while (k > 0) {
                        dd.push_back(k % 10);
                        k /= 10;
                    }
                    reverse(dd.begin(), dd.end());
                    int c = v;
                    for (int t : dd) {
                        if (go[c][t] == -1) {
                            go.push_back(vector<int>(10, -1));
                            vv.push_back(vector<int>(0));
                            h.push_back((h[c] * 10ll + t) % 1000000007);
                            go[c][t] = go.size() - 1;
                        }
                        c = go[c][t];
                    }
//                    cout << "--> " << h[c] << " " << e.first << "\n";
                    vv[c].push_back(e.first);
                }
            }
            for (int t = 0; t <= 9; t++) {
                if (go[v][t] != -1) {
                    cur2.push_back(go[v][t]);
                }
            }
        }
        cur = cur2;
    }
    for (int i = 1; i < n; i++) {
        cout << d[i] << "\n";
    }

    return 0;
}