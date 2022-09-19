#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int n, m;
int mm;
int fr[5000000];
int e[5000000];
int ww[5000000];
bool used[5000000];

struct graph {
    vector<vector<int>> g;
    int odd = 0;

    void add_edge(int x, int y) {
        e[mm] = y;
        fr[mm] = x;
        g[x].push_back(mm);
        mm++;
        e[mm] = x;
        fr[mm] = y;
        g[y].push_back(mm);
        mm++;
    }

    vector<int> pp;

    void go(int v) {
        while (!g[v].empty()) {
            if (used[g[v].back() / 2]) {
                g[v].pop_back();
                continue;
            }
            int i = g[v].back();
            used[i / 2] = true;
            g[v].pop_back();
            go(e[i]);
            pp.push_back(i);
        }
    }

    vector<vector<int>> paths;
    vector<vector<int>> cycles;

    void euler() {
        int p = -1;
        for (int i = 0; i < n; i++) {
            if (g[i].size() % 2 == 1) {
                odd++;
                if (p == -1) {
                    p = i;
                } else {
//                    cout << i + 1 << " " << p + 1 << "\n";
                    add_edge(i, p);
                    p = -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!g[i].empty()) {
                pp.clear();
                pp.resize(0);
                go(i);
                reverse(pp.begin(), pp.end());
                int nn = (int)pp.size();
                int s = -1;
                for (int j = 0; j < nn; j++) {
                    if (pp[j] >= 2 * m) {
                        s = j;
                    }
                }
                if (s == -1) {
                    cycles.push_back(pp);
                } else {
                    vector<int> p;
                    for (int i = 0; i <= nn; i++) {
                        if (i == nn || pp[(s + i) % nn] >= 2 * m) {
                            if (!p.empty()) paths.push_back(p);
                            p.clear();
                        } else {
                            p.push_back(pp[(s + i) % nn]);
                        }
                    }
                }
            }
        }
//        cout << "paths:\n";
//        for (auto pp : paths) {
//            for (auto x : pp) {
//                cout << fr[x] + 1 << "-" << e[x] + 1 << " ";
//            }
//            cout << "\n";
//        }
//        cout << "cycles:\n";
//        for (auto pp : cycles) {
//            for (auto x : pp) {
//                cout << fr[x] + 1 << "-" << e[x] + 1 << " ";
//            }
//            cout << "\n";
//        }
    }
};

graph g1, g2;


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g1.g.resize(n);
    g2.g.resize(n);
    mm = 0;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        ww[2 * i] = ww[2 * i + 1] = w;
        if (w == 1) {
            g1.add_edge(x, y);
        } else {
            g2.add_edge(x, y);
        }
    }
    g1.euler();
    g2.euler();

    vector<int> res(m);

    for (auto &p : g1.cycles) {
        for (auto ee: p) {
            res[ee / 2] = ee % 2 + 1;
        }
    }
    for (auto &p : g2.cycles) {
        for (auto ee: p) {
            res[ee / 2] = ee % 2 + 1;
        }
    }

    vector<int> e1(n, -1);
    vector<bool> done1(g1.paths.size());
    vector<int> e2(n, -1);
    vector<bool> done2(g2.paths.size());

    for (int i = 0; i < (int)g1.paths.size(); i++) {
        auto &p = g1.paths[i];
        int s = fr[p[0]];
        int f = e[p.back()];
        e1[s] = e1[f] = i;
    }
    for (int i = 0; i < (int)g2.paths.size(); i++) {
        auto &p = g2.paths[i];
        int s = fr[p[0]];
        int f = e[p.back()];
        e2[s] = e2[f] = i;
    }
    for (int i = 0; i < (int)g1.paths.size(); i++) {
        if (done1[i]) continue;
        int k = i;
        int st = 1;
        while (true) {
            if (st == 1) {
                if (done1[k]) break;
                auto &p = g1.paths[k];
                for (auto ee: p) {
                    res[ee / 2] = ee % 2 + 1;
                }
                done1[k] = true;
                int v = e[g1.paths[k].back()];
                int kk = e2[v];
                if (kk == -1) break;
                if (fr[g2.paths[kk][0]] != v) {
                    reverse(g2.paths[kk].begin(), g2.paths[kk].end());
                    for (int & j : g2.paths[kk]) {
                        j ^= 1;
                    }
                }
                k = kk;
                st = 2;
            } else {
                if (done2[k]) break;
                auto &p = g2.paths[k];
                for (auto ee: p) {
                    res[ee / 2] = ee % 2 + 1;
                }
                done2[k] = true;
                int v = e[g2.paths[k].back()];
                int kk = e1[v];
                if (kk == -1) break;
                if (fr[g1.paths[kk][0]] != v) {
                    reverse(g1.paths[kk].begin(), g1.paths[kk].end());
                    for (int & j : g1.paths[kk]) {
                        j ^= 1;
                    }
                }
                k = kk;
                st = 1;
            }
        }
        done1[i] = false;
        k = i;
        st = 1;
        while (true) {
            if (st == 1) {
                if (done1[k]) break;
                auto &p = g1.paths[k];
                for (auto ee: p) {
                    res[ee / 2] = ee % 2 + 1;
                }
                done1[k] = true;
                int v = fr[g1.paths[k][0]];
                int kk = e2[v];
                if (kk == -1) break;
                if (e[g2.paths[kk].back()] != v) {
                    reverse(g2.paths[kk].begin(), g2.paths[kk].end());
                    for (int & j : g2.paths[kk]) {
                        j ^= 1;
                    }
                }
                k = kk;
                st = 2;
            } else {
                if (done2[k]) break;
                auto &p = g2.paths[k];
                for (auto ee: p) {
                    res[ee / 2] = ee % 2 + 1;
                }
                done2[k] = true;
                int v = fr[g2.paths[k][0]];
                int kk = e1[v];
                if (kk == -1) break;
                if (e[g1.paths[kk].back()] != v) {
                    reverse(g1.paths[kk].begin(), g1.paths[kk].end());
                    for (int & j : g1.paths[kk]) {
                        j ^= 1;
                    }
                }
                k = kk;
                st = 1;
            }
        }
    }
    for (int i = 0; i < (int)g2.paths.size(); i++) {
        if (done2[i]) continue;
        auto &p = g2.paths[i];
        for (auto ee: p) {
            res[ee / 2] = ee % 2 + 1;
        }
    }

    vector<int> d(n);
    for (int i = 0; i < m; i++) {
        if (res[i] == 1) {
            d[e[2 * i]] += ww[i * 2];
            d[e[2 * i + 1]] -= ww[i * 2];
        } else {
            d[e[2 * i]] -= ww[i * 2];
            d[e[2 * i + 1]] += ww[i * 2];
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (abs(d[i]) == 1) c++;
    }
//    cout << c << " " << g1.odd << "\n";
//    for (int x : d) {
//        cout << x << " ";
//    }
//    cout << "\n";
    assert(c == g1.odd);

    cout << g1.odd << "\n";
    for (int x: res) cout << x;
    cout << "\n";

    return 0;
}